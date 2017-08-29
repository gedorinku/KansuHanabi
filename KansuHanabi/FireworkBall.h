#pragma once
#include <deque>
#include <vector>
#include <memory>
#include <Siv3D/Vector2D.hpp>
#include <Siv3D/EasingController.hpp>
#include "Firework.h"
#include "TrajectoryParticle.h"
#include "NormalFirework.h"
#include "Function/Function.h"

namespace hanabi {
	class FireworkBall
	{
	public:
		template <class T>
		FireworkBall(const T& firework, const s3d::Vec2& start, const s3d::Vec2& end);
		~FireworkBall();

		bool draw();

		bool isAlive() const;

	private:
		std::shared_ptr<Firework> firework;
		s3d::EasingController<s3d::Vec2> position;
		std::deque<TrajectoryParticle> trajectory;
		std::vector<NormalFirework> childFireworks;
		bool launched;
		bool blasted;
		s3d::Vec2 start;
		s3d::Vec2 end;

		static const std::array<Function*, 3> functions;
	};

	template <class T>
	hanabi::FireworkBall::FireworkBall(const T& firework, const Vec2& start, const Vec2& end)
		: firework(std::make_shared<T>(firework)),
		position(start, end, Easing::Linear, (end - start).length() * 10.0),
		trajectory(),
		launched(false),
		blasted(false),
		start(start),
		end(end)
	{
	}
}

