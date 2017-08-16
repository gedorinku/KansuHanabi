#include "XYGraph.h"
#include <Siv3D.hpp>


hanabi::XYGraph::XYGraph(const Function& function)
	: function(function)
{
	for (auto i = -500; i < 500; ++i)
	{
		vertexes.push_back({i, function.evaluate(i / 100.0) * 100.0});
	}
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
