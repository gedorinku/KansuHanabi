#include <array>
#include <memory>
#include <Siv3D.hpp>
#include "Function/Functions.h"
#include "NormalFirework.h"
#include "Graph/XYGraph.h"
#include "Graph/PolarCoordinatesGraph.h"
#include "FireworkBall.h"

void Main()
{
	Window::Resize(1920, 1200);
	const Font font(30);
	//std::array<std::function<hanabi::Function && ()>, 1> functions = {
	//	[]() -> hanabi::Function&& { return hanabi::Cos(); }
	//};
	std::array<hanabi::Function*, 5> functions = {
		new hanabi::Cos(),
		new hanabi::Sin(),
		new hanabi::Fraction(hanabi::Constant(1.0), hanabi::Function::X),
		new hanabi::Fraction(hanabi::Sin(), hanabi::Cos()),
		new hanabi::Sin(hanabi::Function::composeEmplace<hanabi::Sin>(
			hanabi::Fraction(hanabi::Constant(1.0), hanabi::Function::X)
		))
	};
	std::list<hanabi::FireworkBall> balls;
	while (System::Update())
	{
		if (Input::MouseL.clicked) {
			auto index = Random(0, ((int) functions.size()) - 1);
			auto&& firework = hanabi::NormalFirework(hanabi::XYGraph(*(functions[index]), -5.0, 5.0), Mouse::Pos(), 50);
			balls.emplace_back(firework, Vec2{ Mouse::Pos().x, 600 }, Mouse::Pos());
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

		font(Profiler::FPS(), L"fps").draw();
	}
}
