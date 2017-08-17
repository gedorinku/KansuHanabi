#include <array>
#include <memory>
#include <Siv3D.hpp>
#include "Function/Functions.h"
#include "NormalFirework.h"
#include "Graph/XYGraph.h"
#include "Graph/PolarCoordinatesGraph.h"

void Main()
{
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
	//const std::vector<std::unique_ptr<hanabi::Function>> functions = {
	//	std::make_unique<hanabi::Function>(hanabi::Cos()),
	//	std::make_unique<hanabi::Function>(hanabi::Sin())//,
	//	//std::make_unique<hanabi::Fraction>(hanabi::Function::composeEmplace<hanabi::Fraction>(hanabi::Constant(1.0), hanabi::Function::X))
	//};
	std::vector<hanabi::NormalFirework> fireworks;
	auto hoge = hanabi::PolarCoordinatesGraph(*functions[4], -2.0 * Pi, 2.0 * Pi, 300.0);
	while (System::Update())
	{
		hoge.draw();
		if (Input::MouseL.clicked) {
			//auto index = 3;
			auto index = Random(0, ((int) functions.size()) - 1);
			//fireworks.emplace_back(hanabi::NormalFirework(hanabi::XYGraph(*(functions[index]), -5.0, 5.0), Mouse::Pos(), 50));
			fireworks.emplace_back(hanabi::NormalFirework(hanabi::PolarCoordinatesGraph(*(functions[index]), -10.0 * Pi, 10.0 * Pi, 300.0), Mouse::Pos(), 200));
		}

		for (auto& firework : fireworks) {
			firework.draw();
		}

		font(Profiler::FPS(), L"fps").draw();
	}
}
