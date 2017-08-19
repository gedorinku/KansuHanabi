#include <cmath>
#include <Siv3D.hpp>
#include "PolarCoordinatesGraph.h"



hanabi::PolarCoordinatesGraph::PolarCoordinatesGraph(const Function& function, double minTheta, double maxTheta, double maxR)
	: function(function), minTheta(minTheta), maxTheta(maxTheta), maxR(maxR)
{
	constexpr auto rate = 100.0;
	deltaX = 1.0 / rate;
	for (auto theta = minTheta * rate; theta < maxTheta * rate; theta += 1.0)
	{
		const auto r = function.evaluate(theta / rate);
		vertexes.emplace_back(Vec2{ r * std::cos(theta / rate), -r * std::sin(theta / rate) });
	}
}

hanabi::PolarCoordinatesGraph::PolarCoordinatesGraph(const PolarCoordinatesGraph& obj)
	: Graph(obj), function(obj.function), vertexes(obj.vertexes), minTheta(obj.minTheta), maxTheta(obj.maxTheta), maxR(obj.maxR)
{
}

hanabi::PolarCoordinatesGraph::~PolarCoordinatesGraph()
{
}

std::vector<s3d::Vector2D<double>> hanabi::PolarCoordinatesGraph::getVertexes() const
{
	return vertexes;
}

void hanabi::PolarCoordinatesGraph::draw(const s3d::Color& color) const
{
	draw(1.0, color);
}

void hanabi::PolarCoordinatesGraph::draw(double thickness, const s3d::Color& color) const
{
	for (auto vertex : vertexes)
	{
		Circle(vertex * 300.0 + Vec2{300.0, 300.0}, thickness / 2.0).draw(color);
	}
}
