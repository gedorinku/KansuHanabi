#pragma once
#include "FireworkBall.h"

namespace hanabi {


class SilentFireworkBall : public FireworkBall {
public:
	template <class T>
	SilentFireworkBall(const T& firework, const s3d::Vec2& start, const s3d::Vec2& end)
	: FireworkBall<T>(firework, start, end) {}

protected:
	void playSound() override {}
};


}
