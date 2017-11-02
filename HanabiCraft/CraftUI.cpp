#include "CraftUI.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
using namespace HanabiCraft::FunctionSelector;
using namespace HanabiCraft::Bomb;


CraftUI::CraftUI(const RectF & v) : v(v), r3(v.x, v.y, v.w, v.h) {
	selector = SP<Selector>(new Selector(RectF(47*_UTIL_KUSOCONST,
											   567*_UTIL_KUSOCONST,
											   654*_UTIL_KUSOCONST,
											   198*_UTIL_KUSOCONST)));
	SP<Function::AbstractFunction> leaf(new Function::LeafX());
	bombViewer = SP<BombViewer>(new BombViewer(RectF(47*_UTIL_KUSOCONST,
													 121*_UTIL_KUSOCONST,
													 651*_UTIL_KUSOCONST,
													 430*_UTIL_KUSOCONST),
											   leaf));
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
}

void CraftUI::Draw() {
	static Texture mainTex(L"Hanabi-assets/Main.png");
	mainTex.scale(_UTIL_KUSOCONST).draw();
	bombViewer->Draw();
	selector->Draw();
	graphArea->Draw();
}

	std::vector<SP<Function::AbstractFunction>> CraftUI::GetBombs()
	{
		return bombViewer->GetBombs();
	}
	int CraftUI::GetSelectedBombIndex() const
	{
		return bombViewer->GetSelectedIndex();
	}
}
