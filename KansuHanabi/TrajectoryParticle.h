#pragma once
#include <Siv3D/Color.hpp>
#include <Siv3D/Vector2D.hpp>

namespace hanabi {
	class TrajectoryParticle
	{
	public:
		TrajectoryParticle(double x, double y, long lifeTime);
		explicit TrajectoryParticle(s3d::Vec2 position, long lifeTime);
		TrajectoryParticle(const TrajectoryParticle& obj);
		~TrajectoryParticle();

		bool draw(const s3d::Color color = Palette::Orange);

		bool isAlive();

	private:
		s3d::Vec2 position;
		long createdAtMillis;
		long lifeTime;
	};
}

