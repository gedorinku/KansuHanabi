#define _USE_MATH_DEFINES
#include <Siv3D.hpp>
#include <cmath>
#include <cstdio>
#include <vector>
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
#include "FireworkBall.h"
#include "Server.h"
#include "Graph/XYGraph.h"
using namespace HanabiCraft;

int HanabiCount = 1;


std::vector<SP<Function::AbstractFunction>> bombs;
SP<Server> server;
std::list<hanabi::FireworkBall> balls;

void ViewUpdate(std::vector<SP<Function::AbstractFunction>>& bombs)
{
	if (RandomBool(1/30.0)) {
		int index = Random()*HanabiCount;
		Vec2 pos = Vec2(Window::Width()*Random(), Window::Height()*Random());
		auto&& firework = hanabi::NormalFirework(hanabi::XYGraph(bombs[index], -1.0, 1.0), pos, 50);
		balls.emplace_back(firework, Vec2{pos.x, Window::Height()}, pos);
		balls.back().isSilent = true;
	}
	auto generateFirework = [&](SP<Function::AbstractFunction> bomb, Vec2 pos, int size) {
		auto&& firework = hanabi::NormalFirework(hanabi::XYGraph(bomb, -1.0, 1.0), pos, size);
		balls.emplace_back(firework, Vec2{ pos.x, Window::Size().y }, pos);
	};
	if (Input::MouseL.clicked) {
		int id = std::max(HanabiCount - 1, (int)(Random()*HanabiCount));
		generateFirework(bombs[id], Mouse::Pos(), 150);
	}
	else while (!server->request_queue.empty())
	{
		const auto raw = server->request_queue.dequeue();
		//Println(FromUTF8(raw));

		if (raw.find("id:") == 0)
		{
			int id = std::stoi(raw.substr(3, raw.find("x:") - 3));
			Vec2 pos;
			const auto rawPos = raw.substr(raw.find("x:"));
			const auto yIndex = rawPos.find("y:");
			auto hoge = rawPos.substr(2, yIndex - 2);
			const auto windowSize = Window::Size();
			pos.x = std::stod(rawPos.substr(2, yIndex - 2)) * windowSize.x;
			pos.y = std::stod(rawPos.substr(yIndex + 2)) * windowSize.y;

			generateFirework(bombs[id], pos, 150);
		}
	}

	for (auto& ball : balls) {
		ball.draw();
	}

	for (auto it = balls.begin(); it != balls.end();)
	{
		if (it->isAlive())
		{
			it++;
			continue;
		}

		auto temp = it;
		it++;
		balls.erase(temp);
	}

	//font(Profiler::FPS(), L"fps").draw();
}

void Run()
{
	SoundAsset::Register(L"fireworks_launch", L"fireworks1.mp3");
	SoundAsset::Register(L"fireworks_flying", L"flying_hanabi.wav");

	enum Mode
	{
		Craft,
		View
	} state = Mode::Craft;
	CraftUI craftUi(Window::ClientRect());

	while (System::Update())
	{
		if (state == Mode::Craft)
		{
			craftUi.Update();
			craftUi.Draw();

			if (Input::KeyEnter.clicked)
			{
				state = Mode::View;
				bombs = craftUi.GetBombs();
				HanabiCount = craftUi.GetSelectedBombIndex() + 1;
				server = std::make_shared<Server>(bombs.size());
				server->start();
			}
			
		} else if (state == Mode::View)
		{
			ViewUpdate(bombs);

			if (Input::KeySpace.clicked)
			{
				state = Mode::Craft;
			}
		}
	}
}

void Main() {

	for (int i = 0; i < 20; i++) Random();
	Window::Resize((int)(1980*_UTIL_KUSOCONST + 0.5), (int)(1200*_UTIL_KUSOCONST + 0.5));

	enum Mode {
		JustRun,
		Function_PoyoTest,
		BombViewer_PoyoTest,
		BombViewer_BombViewer_UpdateTest,
		Graph_UpdateTest,
		GraphManager_UpdateTest,
		Selector_UpdateTest,
		CraftUI_UpdateTest
	} mode = Mode::JustRun;

	if (mode == JustRun) {
		Run();
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
			graph->Draw();
		}
	}
	else if (mode == GraphManager_UpdateTest) {
		SP<Function::AbstractFunction> f(new Function::Sin(SP<Function::LeafX>(new Function::LeafX())));
		SP<HanabiCraft::Graph::GraphManager> v(new HanabiCraft::Graph::GraphManager(
			0, 0, Window::Width(), Window::Height(), f
		));
		while (System::Update()) {
			v->Update();
			v->Draw();
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
			ui.Draw();
		}
	}
	return;
}
