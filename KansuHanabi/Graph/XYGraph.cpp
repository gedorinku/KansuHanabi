#include <cmath>
#include <Siv3D.hpp>
#include "XYGraph.h"


hanabi::XYGraph::XYGraph(const Function& function, double minX, double maxX)
	: function(function), minX(minX), maxX(maxX)
{
	const auto maxY = std::max(std::abs(minX), std::abs(maxX));
	constexpr auto rate = 100.0;
	deltaX = 1.0 / rate;
	for (auto i = minX * rate; i < maxX * rate; i += 1.0)
	{
		const auto y = -function.evaluate(i / rate);
		if (maxY < std::abs(y)) continue;
		vertexes.emplace_back(Vec2{i / rate, y});
	}
}

hanabi::XYGraph::XYGraph(const XYGraph& obj)
	: XYGraph(obj.function, obj.minX, obj.maxX)
{
}


hanabi::XYGraph::~XYGraph()
{
}

std::vector<Vec2> hanabi::XYGraph::getVertexes() const
{
	return vertexes;
}

void hanabi::XYGraph::draw(const Color& color) const
{
	draw(1.0, color);
}

void hanabi::XYGraph::draw(double thickness, const Color& color) const
{
	for (auto vertex : vertexes)
	{
		Circle(vertex, thickness / 2.0).draw(color);
	}
}
