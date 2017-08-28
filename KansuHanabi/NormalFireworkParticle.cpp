#include <Siv3D.hpp>
#include "NormalFireworkParticle.h"


hanabi::NormalFireworkParticle::NormalFireworkParticle(std::shared_ptr<Image> buffer, const Vec2& parentPosition, const Vec2& start, const Vec2& end, double time)
	: flashProbability(EasingController<int>(500, 0, Easing::Expo, time / 2.0)),
	  position(EasingController<Vec2>(start, end, Easing::Expo, time)),
	  parentPosition(parentPosition),
	  hue(EasingController<double>(0.0, 360.0, Easing::Linear, time)),
	  fired(false),
	  flashStartsAtMillis(0),
	  trajectory(),
	  lastParticleMillis(0L),
	  buffer(buffer)
{
}

hanabi::NormalFireworkParticle::~NormalFireworkParticle()
{
}

void hanabi::NormalFireworkParticle::draw()
{
	if (position.isEnd()) return;

	if (!fired)
	{
		fired = true;
		position.start();
		flashProbability.start();
		firedAtMillis = Time::GetMillisec64();
		hue.start();
	}

	if (Random(0, flashProbability.easeInOut()) == 0)
	{
		flashStartsAtMillis = Time::GetMillisec64();
	}

	auto elapsedTime = Time::GetMillisec64() - firedAtMillis;
	auto nextPosition = position.easeOut() - gravity * elapsedTime * elapsedTime;
	
	if (elapsedTime < 800)
	{
		trajectory.emplace_back(parentPosition + nextPosition, 100);
	}
	for (auto& particle : trajectory)
	{
		particle.draw();
	}
	while (trajectory.size() && !trajectory.front().isAlive())
	{
		trajectory.pop_front();
	}

	if (Time::GetMillisec64() - flashStartsAtMillis <= 20) return;

	Circle(nextPosition, 1.0).overwrite(*buffer, HSV(hue.easeOut(), 0.9, 1.0));
}

bool hanabi::NormalFireworkParticle::isAlive() const
{
	return !position.isEnd();
}
