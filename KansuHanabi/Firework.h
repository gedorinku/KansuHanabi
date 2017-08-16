#pragma once
#include <Siv3D/Vector2D.hpp>

namespace hanabi {
	class Firework
	{
	public:
		Firework(double x, double y);
		explicit Firework(const s3d::Vec2& position);
		virtual ~Firework();

		virtual void draw() = 0;

		const s3d::Vec2 position;
	};
}

