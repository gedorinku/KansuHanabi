#include <Siv3D.hpp>
#include "NormalFirework.h"


hanabi::NormalFirework::NormalFirework(const Graph& graph, double x, double y, double size)
	: NormalFirework(graph, { x, y }, size)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, const s3d::Vec2& position, double size)
	: Firework(position)
{
	auto time = size * 150.0;
	const auto& vertexes = graph.getVertexes();
	for (auto i = 0; i < vertexes.size(); i += vertexes.size() / 100)
	{
		balls.emplace_back(NormalFireworkBall(position, position + vertexes[i] * size, time));
	}
}

hanabi::NormalFirework::~NormalFirework()
{
}

void hanabi::NormalFirework::draw()
{
	for (auto& ball : balls)
	{
		ball.draw();
	}
}
