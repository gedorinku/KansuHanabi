#include "Selector.h"
#include "Function\LeafX.h"
#include "Function\Sin.h"
#include "Function\Plus.h"

namespace HanabiCraft {
namespace FunctionSelector {


Selector::Selector(const RectF & v)
	: v(v)
	, itemOriginX(v.x + margin/2)
	, borderSize(v.h/2)
	, selectedIndex(-1)
	, hold(500, 5)
	, itemCount(20) {
	functions.resize(itemCount);
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	functions[0] = SP<Function::AbstractFunction>(new Function::Sin(leaf));
	SP<Function::AbstractFunction> leaf1(new Function::LeafX());
	SP<Function::AbstractFunction> leaf2(new Function::LeafX());
	functions[1] = SP<Function::AbstractFunction>(new Function::Plus(leaf1, leaf2));
	for (int i = 2; i < itemCount; i++) {
		functions[i] = SP<Function::AbstractFunction>(new Function::LeafX());
	}
}

void Selector::SetOnDrop(std::function<void(SP<Function::AbstractFunction>)> onDrop) {
	this->onDrop = onDrop;
}

RoundRect Selector::GetRect(int index) {
	double x = itemOriginX + (index/2)*borderSize;
	return RoundRect(x + margin/2,
					 v.y + margin + borderSize*(index&1),
					 borderSize - margin,
					 borderSize - margin,
					 4);
}

//TODO: タッチ操作は前回タッチしたところから移動したかのような挙動をするので、itemOriginXが壊れる
void Selector::Update() {
	hold.Update();

	if (!hold.IsHeld() && v.mouseOver && Input::MouseL.pressed) {
		itemOriginX = Max(Min(itemOriginX + Mouse::DeltaF().x, v.x + margin/2),
							v.x + v.w - margin/2 - borderSize*((itemCount + 1)/2));
	}
	if (hold.IsStarted()) {
		selectedIndex = [&]() {
			for (int i = 0; i < itemCount; i++) {
				if (GetRect(i).mouseOver) return i;
			}
			return -1;
		} ();
	}
	if (hold.IsFinished() && selectedIndex != -1 && onDrop) {
		//DeepClone()しないと大変な目に合う
		onDrop(functions[selectedIndex]->DeepClone());
		selectedIndex = -1;
	}
}

void Selector::Draw() {
	RasterizerState rasterizer = RasterizerState::Default2D;
	rasterizer.scissorEnable = true;
	Graphics2D::SetRasterizerState(rasterizer);
	Graphics2D::SetScissorRect(Rect(v.x + 0.5, v.y + 0.5, v.w + 0.5, v.h + 0.5));

	for (int i = 0; i < itemCount; i++) {
		double x = itemOriginX + borderSize*(i/2);
		if (x + borderSize < v.x || v.x + v.w < x) continue;
		GetRect(i).drawFrame(1, 1, Palette::Black);
	}

	Graphics2D::SetRasterizerState(RasterizerState::Default2D);

	if (hold.IsHeld() && selectedIndex != -1) {
		RoundRect(Mouse::PosF() - Vec2((borderSize - margin)/2, (borderSize - margin*2)/2),
				  Vec2(borderSize - margin, borderSize - margin*2), 4).drawFrame(1, 1, Palette::Black);
	}
}


}
}