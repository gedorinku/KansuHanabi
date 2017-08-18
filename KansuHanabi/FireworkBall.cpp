#include <Siv3D.hpp>
#include "FireworkBall.h"


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
