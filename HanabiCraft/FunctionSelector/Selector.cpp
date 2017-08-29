#include "Selector.h"
#include "Function\LeafX.h"
#include "Function\Sin.h"
#include "Function\Plus.h"
#include "Function\Pow.h"
#include "Function\Tan.h"
#include "Function\X.h"
#include "Function\Log.h"
#include "Function\Time.h"
#include "Function\Abs.h"

namespace HanabiCraft {
namespace FunctionSelector {


Selector::Selector(const RectF & v)
	: v(v)
	, itemOriginX(v.x + margin/2)
	, borderSize(v.h/2)
	, selectedIndex(-1)
	, hold(500, 5)
	, itemCount(15) {
	functions.resize(itemCount);
	names.resize(itemCount);

	using namespace HanabiCraft::Function;

	names[0] = L"x(leaf)";
	functions[0] = LeafX::Build();

	names[1] = L" x ";
	functions[1] = X::Build(LeafX::Build());

	names[2] = L"たす";
	functions[2] = Plus::Build(LeafX::Build(), LeafX::Build());

	names[3] = L"かける";
	functions[3] = Time::Build(LeafX::Build(), LeafX::Build());

	names[4] = L"さいん";
	functions[4] = Sin::Build(LeafX::Build());

	names[5] = L"たん";
	functions[5] = Tan::Build(LeafX::Build());

	names[6] = L"ぜったいち";
	functions[6] = Abs::Build(LeafX::Build());

	names[7] = L"ろぐ";
	functions[7] = Log::Build(LeafX::Build());

	names[8] = L"-2じょう";
	functions[8] = Pow<-2>::Build(LeafX::Build());
	names[9] = L"-1じょう";
	functions[9] = Pow<-1>::Build(LeafX::Build());
	names[10] = L"0じょう";
	functions[10] = Pow<0>::Build(LeafX::Build());
	names[11] = L"2じょう";
	functions[11] = Pow<2>::Build(LeafX::Build());
	names[12] = L"3じょう";
	functions[12] = Pow<3>::Build(LeafX::Build());
	names[13] = L"4じょう";
	functions[13] = Pow<4>::Build(LeafX::Build());
	names[14] = L"5じょう";
	functions[14] = Pow<5>::Build(LeafX::Build());
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

Vec2 Selector::GetCenter(int index) {
	return GetRect(index).center;
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
		static Font font(10);
		Vec2 v(font(names[i]).region().w/2, font(names[i]).region().h/2);
		font(names[i]).draw(GetCenter(i) - v, Palette::Darkblue);
	}

	Graphics2D::SetRasterizerState(RasterizerState::Default2D);

	if (hold.IsHeld() && selectedIndex != -1) {
		RoundRect(Mouse::PosF() - Vec2((borderSize - margin)/2, (borderSize - margin*2)/2),
				  Vec2(borderSize - margin, borderSize - margin*2), 4).drawFrame(1, 1, Palette::Black);
	}
}


}
}