#include "XYGraph.h"
#include <Siv3D.hpp>


hanabi::XYGraph::XYGraph(const Function& function)
	: function(function)
{
	for (auto i = 0; i < 100; ++i)
	{
		vertexes.push_back({300.0 + i, 100.0 - function.evaluate(i / 100.0) * 100.0});
	}
}


hanabi::XYGraph::~XYGraph()
{
}

Array<Vec2> hanabi::XYGraph::getVertexes() const
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
