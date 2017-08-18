#pragma once
#include <deque>
#include <Siv3D/EasingController.hpp>
#include <Siv3D/Vector2D.hpp>
#include "TrajectoryParticle.h"

namespace hanabi {
	class NormalFireworkParticle
	{
	public:
		NormalFireworkParticle(const s3d::Vec2& start, const s3d::Vec2& end, double time);
		~NormalFireworkParticle();

		void draw();

	private:
		s3d::EasingController<int> flashProbability;
		s3d::EasingController<s3d::Vec2> position;
		s3d::EasingController<double> hue;
		bool fired;
		long flashStartsAtMillis;
		long firedAtMillis;
		std::deque<TrajectoryParticle> trajectory;
		long lastParticleMillis;
	};
}

