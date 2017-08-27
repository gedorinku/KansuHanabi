#include "Selector.h"
#include "Function\LeafX.h"
#include "Function\Sin.h"

namespace HanabiCraft {
namespace FunctionSelector {


Selector::Selector(const RectF & v)
	: v(v)
	, itemOriginX(v.x + margin/2)
	, borderSize(v.h)
	, selectedIndex(-1)
	, hold(500, 5) {
	functions.resize(itemCount);
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	functions[0] = SP<Function::AbstractFunction>(new Function::Sin(leaf));
	for (int i = 1; i < itemCount; i++) {
		functions[i] = SP<Function::AbstractFunction>(new Function::LeafX());
	}
}

void Selector::SetOnDrop(std::function<void(SP<Function::AbstractFunction>)> onDrop) {
	this->onDrop = onDrop;
}

void Selector::Update() {
	hold.Update();

	if (!hold.IsHeld() && v.mouseOver && Input::MouseL.pressed) {
		itemOriginX = Max(Min(itemOriginX + Mouse::DeltaF().x, v.x + margin/2),
							v.x + v.w - margin/2 - borderSize*itemCount);
	}
	if (hold.IsStarted()) {
		selectedIndex = [&]() {
			for (int i = 0; i < itemCount; i++) {
				double x = itemOriginX + borderSize*i;
				RoundRect rect(x + margin/2, v.y + margin, borderSize - margin, borderSize - margin*2, 4);
				if (rect.mouseOver) return i;
			}
			return -1;
		} ();
	}
	if (hold.IsFinished() && selectedIndex != -1 && onDrop) {
		//DeepClone()‚µ‚È‚¢‚Æ‘å•Ï‚È–Ú‚É‡‚¤
		onDrop(functions[selectedIndex]->DeepClone());
		selectedIndex = -1;
	}
}

void Selector::Draw() {
	v.draw(Palette::White);
	v.drawFrame(1, 1, Palette::Black);
	RasterizerState rasterizer = RasterizerState::Default2D;
	rasterizer.scissorEnable = true;
	Graphics2D::SetRasterizerState(rasterizer);
	Graphics2D::SetScissorRect(Rect(v.x + 0.5, v.y + 0.5, v.w + 0.5, v.h + 0.5));

	for (int i = 0; i < itemCount; i++) {
		double x = itemOriginX + borderSize*i;
		if (x + borderSize < v.x || v.x + v.w < x) continue;
		RoundRect(x + margin/2, v.y + margin, borderSize - margin, borderSize - margin*2, 4)
			.drawFrame(1, 1, Palette::Black);
	}

	Graphics2D::SetRasterizerState(RasterizerState::Default2D);

	if (hold.IsHeld() && selectedIndex != -1) {
		RoundRect(Mouse::PosF() - Vec2((borderSize - margin)/2, (borderSize - margin*2)/2),
				  Vec2(borderSize - margin, borderSize - margin*2), 4).drawFrame(1, 1, Palette::Black);
	}
}


}
}