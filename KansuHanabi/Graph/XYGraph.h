#pragma once
#include <vector>
#include "Graph.h"
#include "../Function/Function.h"

namespace hanabi {
	class XYGraph :
		public Graph
	{
	public:
		explicit XYGraph(const Function& function, double minX, double maxX);
		XYGraph(const XYGraph& obj);
		~XYGraph() override;

		std::vector<s3d::Vector2D<double>> getVertexes() const override;

		void draw(const s3d::Color& color = s3d::Palette::White) const override;

		void draw(double thickness, const s3d::Color& color = s3d::Palette::White) const override;

	private:
		const Function& function;
		std::vector<s3d::Vector2D<double>> vertexes;
		double minX;
		double maxX;
	};
}

