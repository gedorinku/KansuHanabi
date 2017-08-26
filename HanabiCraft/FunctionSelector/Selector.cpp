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
	, isDragged(false) {
	functions.resize(itemCount);
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	functions[0] = SP<Function::AbstractFunction>(new Function::Sin(leaf));
	for (int i = 1; i < itemCount; i++) {
		functions[i] = SP<Function::AbstractFunction>(new Function::LeafX());
	}
}

void Selector::Update() {
	if (v.mouseOver && Input::MouseL.clicked) {
		clickedPos = Mouse::PosF();
	}
	if (v.mouseOver && Input::MouseL.pressed) {
		if (!isDragged) {
			itemOriginX = Max(Min(itemOriginX + Mouse::DeltaF().x, v.x + margin/2),
							  v.x + v.w - margin/2 - borderSize*itemCount);
		}
	}

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
}


}
}