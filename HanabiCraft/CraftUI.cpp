#include "CraftUI.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
using namespace HanabiCraft::FunctionSelector;
using namespace HanabiCraft::Bomb;


CraftUI::CraftUI(const RectF & v) : v(v), r3(v.x + v.w*0.6, v.y, v.w*0.4, v.h) {
	selector = SP<Selector>(new Selector(RectF(v.x, v.y + v.h*0.8, v.w*0.6, v.h*0.2)));
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	bombViewer = SP<BombViewer>(new BombViewer(RectF(v.x, v.y, v.w*0.6, v.h*0.8), leaf));
	selector->SetOnDrop([&](SP<Function::AbstractFunction> f) {bombViewer->Drop(f); });
	graphArea = SP<Graph::GraphArea>(new Graph::GraphArea(r3, bombViewer->SelectedPowder()));

	bombViewer->SetOnChange([&](const BombViewer &sender) {
		graphArea = SP<Graph::GraphArea>(new Graph::GraphArea(r3, sender.SelectedPowder()));
	});
}

void CraftUI::Update() {
	//selector::Update()を先に呼ばないとドラッグ&ドロップと同時に潜る操作が発生する
	selector->Update();
	bombViewer->Update();
	graphArea->Update();
	bombViewer->Draw();
	selector->Draw();
	graphArea->Draw();
}


}