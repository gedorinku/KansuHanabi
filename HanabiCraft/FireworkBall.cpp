#include <Siv3D.hpp>
#include "FireworkBall.h"
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
		firework->draw();
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
