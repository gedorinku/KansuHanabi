#pragma once
#include <vector>
#include <Siv3D/Vector2D.hpp>

namespace hanabi {
	class Graph
	{
	public:
		Graph();
		virtual ~Graph();

		virtual std::vector<s3d::Vector2D<double>> getVertexes() const = 0;

		virtual void draw(const s3d::Color& color = s3d::Palette::White) const = 0;

		virtual void draw(double thickness, const s3d::Color& color = s3d::Palette::White) const = 0;
	};
}

