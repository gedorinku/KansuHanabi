#pragma once
#include <memory>
#include "Firework.h"
#include "Graph/GraphGe.h"
#include "NormalFireworkParticle.h"

namespace hanabi {
	class NormalFirework
		: public Firework
	{
	public:
		NormalFirework(const NormalFirework& obj);
		NormalFirework(const Graph& graph, double x, double y, double size);
		NormalFirework(const Graph& graph, const s3d::Vec2& position, double size);
		~NormalFirework() override;

		void draw() override;

		bool isAlive() const override;

	private:
		std::vector<NormalFireworkParticle> balls;
		std::shared_ptr<s3d::Image> buffer;
		s3d::DynamicTexture texture;
		s3d::DynamicTexture blurredTexture;
		s3d::Vec2 delta;
		s3d::EasingController<double> scale;
		long long startAtMillis;
		double lifeTime;
	};
}

