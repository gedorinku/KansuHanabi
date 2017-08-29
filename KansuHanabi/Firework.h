#pragma once
#include <Siv3D/Vector2D.hpp>

namespace hanabi {
	class Firework
	{
	public:
		Firework(const Firework& obj);
		Firework(double x, double y);
		explicit Firework(const s3d::Vec2& position);
		virtual ~Firework();

		virtual void draw() = 0;

		virtual bool isAlive() const = 0;

		const s3d::Vec2 position;
	};
}

