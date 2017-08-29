#pragma once
#include <deque>
#include <memory>
#include <Siv3D/EasingController.hpp>
#include <Siv3D/Vector2D.hpp>
#include "TrajectoryParticle.h"

namespace hanabi {
	class NormalFireworkParticle
	{
	public:
		NormalFireworkParticle(std::shared_ptr<Image> buffer, const s3d::Vec2& parentPosition, const s3d::Vec2& start, const s3d::Vec2& end, double time);
		~NormalFireworkParticle();

		void draw();

		bool isAlive() const;

		constexpr static Vec2 gravity = Vec2{ 0.0, -0.000005 };

	private:
		s3d::EasingController<int> flashProbability;
		s3d::EasingController<s3d::Vec2> position;
		s3d::Vec2 parentPosition;
		s3d::EasingController<double> hue;
		bool fired;
		long flashStartsAtMillis;
		long firedAtMillis;
		std::deque<TrajectoryParticle> trajectory;
		long lastParticleMillis;
		std::shared_ptr<Image> buffer;
	};
}

