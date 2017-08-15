# include <Siv3D.hpp>
# include "Function/Functions.h"
#include "Graph/XYGraph.h"

using Function = hanabi::Function;

void Main()
{
	const Font font(30);
	std::vector<Vector2D<double>> dots;
	constexpr double RATE = 100.0;
	const double INF = pow(10.0, 10.0);
	auto fun = Function::composeEmplace<hanabi::Fraction>(hanabi::Constant(1), Function::X);
	auto graph = hanabi::XYGraph(fun);
	//auto fun = Function::composeEmplace<hanabi::Fraction>(hanabi::Constant(1), Function::X);
	//auto fun = hanabi::Sin();
	//assert(fun.evaluate(1.0) == std::cos(std::sin(1.0)));
	for (double i = -300.0; i < 300.0; i += 0.01)
	{
		//dots.emplace_back(Vector2D<double>(300 + i, 250 + sin(1 / (i / 220.0)) * 220.0));
		dots.emplace_back(Vector2D<double>(300 + i, 300 - fun.evaluate(i / RATE) * RATE));
	}

	std::vector<std::pair<Circle, Color>> hanabi;
	for (int i = 0; i < dots.size(); ++i)
	{
		if (Random(400) != 0) continue;
		hanabi.emplace_back(std::make_pair(Circle(dots[i], 2.0), RandomColor()));
	}

	while (System::Update())
	{
		graph.draw();
//		//font(L"ようこそ、Siv3D の世界へ！").draw();
//
//		for (int i = 0; i < dots.size(); ++i)
//		{
//			if (INF < abs(dots[i].y)) continue;
//			//Line(dots[i], dots[i]).draw();
//			dots[i].draw();
//		}
//
//		for (auto dot : hanabi)
//		{
//			//dot.first.draw(dot.second);
//		}
	}
}
