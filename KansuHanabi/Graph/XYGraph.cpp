#include "XYGraph.h"
#include <Siv3D.hpp>


hanabi::XYGraph::XYGraph(const Function& function, double minX, double maxX)
	: function(function), minX(minX), maxX(maxX)
{
	for (auto i = minX * 100; i < maxX * 100; ++i)
	{
		vertexes.push_back({i / 100.0, function.evaluate(i / 100.0)});
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
