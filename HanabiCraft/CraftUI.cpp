#include "CraftUI.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
using namespace HanabiCraft::FunctionSelector;
using namespace HanabiCraft::Bomb;


CraftUI::CraftUI(const RectF & v) : v(v) {
	selector = SP<Selector>(new Selector(RectF(v.x, v.y + v.h*0.8, v.w, v.h*0.2)));
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	bombViewer = SP<BombViewer>(new BombViewer(RectF(v.x, v.y, v.w, v.h*0.8), leaf));
	selector->SetOnDrop([&](SP<Function::AbstractFunction> f) {bombViewer->Drop(f); });
}

void CraftUI::Update() {
	//selector::Update()を先に呼ばないとドラッグ&ドロップと同時に潜る操作が発生する
	selector->Update();
	bombViewer->Update();
	bombViewer->Draw();
	selector->Draw();
}


}