#pragma once
#include <vector>
#include "../Function/Function.h"
#include "Graph.h"

namespace hanabi {
	class PolarCoordinatesGraph :
		public Graph
	{
	public:
		PolarCoordinatesGraph(const Function& function, double minTheta, double maxTheta, double maxR);
		PolarCoordinatesGraph(const PolarCoordinatesGraph& obj);
		~PolarCoordinatesGraph() override;

		std::vector<s3d::Vector2D<double>> getVertexes() const override;

		void draw(const s3d::Color& color = s3d::Palette::White) const override;

		void draw(double thickness, const s3d::Color& color = s3d::Palette::White) const override;

	private:
		const Function& function;
		std::vector<s3d::Vector2D<double>> vertexes;
		double minTheta;
		double maxTheta;
		double maxR;
	};
}

