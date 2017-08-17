#include <Siv3D.hpp>
#include "NormalFireworkBall.h"



hanabi::NormalFireworkBall::NormalFireworkBall(const s3d::Vec2& start, const s3d::Vec2& end, double time)
	: flashProbability(EasingController<int>(500, 0, Easing::Expo, time / 2.0)),
		position(EasingController<Vec2>(start, end, Easing::Expo, time)),
		fired(false), flashStartsAtMillis(0)
{
}

hanabi::NormalFireworkBall::~NormalFireworkBall()
{
}

void hanabi::NormalFireworkBall::draw()
{
	if (!fired)
	{
		fired = true;
		position.start();
		flashProbability.start();
	}

	if (Random(0, flashProbability.easeInOut()) == 0)
	{
		flashStartsAtMillis = Time::GetMillisec64();
	}

	if (Time::GetMillisec64() - flashStartsAtMillis <= 20) return;
	Circle(position.easeOut(), 1.0).draw(s3d::Palette::Orange);
}
