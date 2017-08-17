#include <cmath>
#include <Siv3D.hpp>
#include "NormalFirework.h"


hanabi::NormalFirework::NormalFirework(const Graph& graph, double x, double y, double size)
	: NormalFirework(graph, { x, y }, size)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, const s3d::Vec2& position, double size)
	: Firework(position)
{
	auto time = size * 125.0;
	const auto& vertexes = graph.getVertexes();
	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<double> length(0.0, 4.0);
	for (auto i = 0; i < vertexes.size(); i += std::max(vertexes.size() / 100, (unsigned int) 1))
	{
		auto noise = RandomVec2(length(mt));
		balls.emplace_back(NormalFireworkBall(position, position + vertexes[i] * size + noise, time));
	}
}

hanabi::NormalFirework::~NormalFirework()
{
}

void hanabi::NormalFirework::draw()
{
	Graphics2D::SetBlendState(BlendState::Additive);
	for (auto& ball : balls)
	{
		ball.draw();
	}
	Graphics2D::SetBlendState(BlendState::Default);
}
