#define _USE_MATH_DEFINES
#include <Siv3D.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "Util.h"
#include "Function\Sin.h"
#include "Function\LeafX.h"
#include "Bomb\OneArgPowder.h"
#include "Bomb\LeafXPowder.h"
#include "Bomb\AbstractGunPowder.h"
#include "Bomb\PowderBuilder.h"
#include "Bomb\BombViewer.h"
#include "Graph\GraphManager.h"
#include "Graph\GraphManager.h"
#include "TmpClass.h"
#include "FunctionSelector\Selector.h"
#include "CraftUI.h"
using namespace HanabiCraft;

void Main() {
	for (int i = 0; i < 20; i++) Random();

	enum Mode {
		JustRun,
		Function_PoyoTest,
		BombViewer_PoyoTest,
		BombViewer_BombViewer_UpdateTest,
		Graph_UpdateTest,
		GraphManager_UpdateTest,
		Selector_UpdateTest,
		CraftUI_UpdateTest
	} mode = Mode::CraftUI_UpdateTest;

	if (mode == JustRun) {
	}
	else if (mode == Function_PoyoTest) {
		using namespace Function;
		Console::Open();
		printf("%f\n", Function::Sin(SP<AbstractFunction>(new LeafX())).Eval(M_PI*3/2));
	} 
	else if (mode == BombViewer_PoyoTest) {
		using namespace Function;
		SP<AbstractFunction> g(new Function::Sin(SP<AbstractFunction>(new LeafX())));
		SP<AbstractFunction> f(new Function::Sin(SP<AbstractFunction>(g)));
		SP<Bomb::AbstractGunPowder> p(Bomb::PowderBuilder(f).Build());
		Graphics::SetBackground(Palette::White);
		while (System::Update()) {
			p->Draw(Circle(Vec2(Window::Width()/2.0, Window::Height()/2.0), 100));
		}
	}
	else if (mode == BombViewer_BombViewer_UpdateTest) {
		using namespace Function;
		SP<AbstractFunction> g(new Function::Sin(SP<AbstractFunction>(new LeafX())));
		SP<AbstractFunction> f(new Function::Sin(SP<AbstractFunction>(g)));
		Bomb::BombViewer viewer(Window::ClientRect(), f);
		while (System::Update()) {
			viewer.Update();
		}
	}
	else if (mode == Graph_UpdateTest) {
		SP<Function::AbstractFunction> f(new Function::Sin(SP<Function::LeafX>(new Function::LeafX())));
		SP<Graph::Graph> graph(new Graph::Graph(0, 0, Window::Width(), Window::Height(), f));
		while (System::Update()) {
			graph->Update();
		}
	}
	else if (mode == GraphManager_UpdateTest) {
		SP<Function::AbstractFunction> f(new Function::Sin(SP<Function::LeafX>(new Function::LeafX())));
		SP<HanabiCraft::Graph::GraphManager> v(new HanabiCraft::Graph::GraphManager(
			0, 0, Window::Width(), Window::Height(), f
		));
		while (System::Update()) {
			v->Update();
		}
		TmpClass t; t.Hoge();
	}
	else if (mode == Selector_UpdateTest) {
		FunctionSelector::Selector s(RectF(0, 0, Window::Width(), 50));
		while (System::Update()) {
			s.Update();
		}
	}
	else if (mode == CraftUI_UpdateTest) {
		CraftUI ui(Window::ClientRect());
		while (System::Update()) {
			ui.Update();
		}
	}
	return;
}
