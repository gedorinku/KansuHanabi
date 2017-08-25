#define _USE_MATH_DEFINES
#include <Siv3D.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "Util.h"
#include "Function\Sin.h"
#include "Function\LeafX.h"
#include "BombViewer\OneArgPowder.h"
#include "BombViewer\LeafXPowder.h"
#include "BombViewer\IGunPowder.h"
#include "BombViewer\PowderBuilder.h"
#include "Graph\GraphManager.h"
#include "Graph\GraphManager.h"
using namespace HanabiCraft;

void Main() {
	enum Mode {
		JustRun,
		Function_PoyoTest,
		BombViewer_PoyoTest,
		Graph_UpdateTest,
		GraphManager_UpdateTest
	} mode = Mode::GraphManager_UpdateTest;

	if (mode == JustRun) {
	}
	else if (mode == Function_PoyoTest) {
		using namespace Function;
		Console::Open();
		printf("%f\n", Function::Sin(SP<AbstractFunction>(new LeafX())).Eval(M_PI*3/2));
	} 
	else if (mode == BombViewer_PoyoTest) {
		using namespace BombViewer;
		using namespace Function;
		SP<AbstractFunction> f(new Function::Sin(SP<AbstractFunction>(new LeafX())));
		SP<IGunPowder> p(BombViewer::PowderBuilder(f).Build(Vec2(Window::Width()/2.0, Window::Height()/2.0), 100));
		while (System::Update()) {
			p->Update();
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
	}
	return;
}
