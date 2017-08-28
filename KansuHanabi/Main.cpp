#include <array>
#include <memory>
#include <Siv3D.hpp>
#include <array>
#include <memory>
#include <Siv3D.hpp>
#include "Function/Functions.h"
#include "NormalFirework.h"
#include "Graph/XYGraph.h"
#include "FireworkBall.h"
#include "Server.h"


void Main()
{
	Window::Resize(1920, 1200);
	const Font font(30);
	std::array<hanabi::Function*, 5> functions = {
		new hanabi::Cos(),
		new hanabi::Sin(),
		new hanabi::Fraction(hanabi::Constant(1.0), hanabi::Function::X),
		new hanabi::Fraction(hanabi::Sin(), hanabi::Cos()),
		new hanabi::Sin(hanabi::Function::composeEmplace<hanabi::Sin>(
			hanabi::Fraction(hanabi::Constant(1.0), hanabi::Function::X)
			))
	};
	Server server(5);
	server.start();
	std::list<hanabi::FireworkBall> balls;

	while (System::Update())
	{
		while (!server.request_queue.empty())
		{
			const auto raw = server.request_queue.dequeue();
			Println(FromUTF8(raw));

			if (raw.find("id:") == 0)
			{
				Vec2 pos;
				const auto rawPos = raw.substr(raw.find("x:"));
				const auto yIndex = rawPos.find("y:");
				auto hoge = rawPos.substr(2, yIndex - 2);
				const auto windowSize = Window::Size();
				pos.x = std::stod(rawPos.substr(2, yIndex - 2)) * windowSize.x;
				pos.y = std::stod(rawPos.substr(yIndex + 2)) * windowSize.y;

				auto index = Random(0, ((int)functions.size()) - 1);
				auto&& firework = hanabi::NormalFirework(hanabi::XYGraph(*(functions[index]), -5.0, 5.0), pos, 50);
				balls.emplace_back(firework, Vec2{ pos.x, 600 }, pos);
			}
		}

		if (Input::MouseL.clicked) {
			auto index = Random(0, ((int)functions.size()) - 1);
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
