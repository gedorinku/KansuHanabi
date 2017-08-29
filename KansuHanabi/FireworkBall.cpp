#include <Siv3D.hpp>
#include "FireworkBall.h"
#include "Function/Constant.h"
#include "Function/Fraction.h"
#include "Function/Sin.h"
#include "Function/Cos.h"
#include "Graph/XYGraph.h"


hanabi::FireworkBall::~FireworkBall()
{
}

bool hanabi::FireworkBall::draw()
{
	for (auto& particle : trajectory)
	{
		particle.draw();
	}
	while (trajectory.size() && !trajectory.front().isAlive())
	{
		trajectory.pop_front();
	}

	if (position.isEnd())
	{
		if (childFireworks.empty()) {
			const int count = Random(0, 5);
			for (int i = 0; i < count; ++i)
			{
				const int index = Random(0, static_cast<int>(functions.size()) - 1);
				const Vec2 delta = RandomVec2(Circle(end, 200));
				childFireworks.emplace_back(XYGraph(*(functions[index]), -5.0, 5.0), delta, 10);
			}
		}

		firework->draw();
		for (int i = 0; i < childFireworks.size(); ++i)
		{
			childFireworks[i].draw();
		}
		return false;
	}

	if (!launched)
	{
		launched = true;
		SoundAsset(L"fireworks_launch").playMulti();
		SoundAsset(L"fireworks_flying").playMulti();
		position.start();
	}

	const auto nextPosition = position.easeOut();

	trajectory.emplace_back(nextPosition, 100);

	Circle(nextPosition, 1.0).draw(Palette::Orange);

	return true;
}

bool hanabi::FireworkBall::isAlive() const
{
	return firework->isAlive();
}

const std::array<hanabi::Function*, 3> hanabi::FireworkBall::functions = {
	new hanabi::Cos(),
	new hanabi::Sin(),
	new hanabi::Fraction(hanabi::Constant(1.0), hanabi::Function()),
};
