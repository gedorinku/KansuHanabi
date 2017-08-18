#pragma once
#include "Firework.h"
#include "Graph/Graph.h"
#include "NormalFireworkParticle.h"

namespace hanabi {
	class NormalFirework
		: public Firework
	{
	public:
		NormalFirework(const Graph& graph, double x, double y, double size);
		NormalFirework(const Graph& graph, const s3d::Vec2& position, double size);
		~NormalFirework() override;

		void draw() override;

	private:
		std::vector<NormalFireworkParticle> balls;
	};
}

