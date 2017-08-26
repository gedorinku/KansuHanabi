#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Graph.h"
#include "Function\AbstractFunction.h"

namespace HanabiCraft {
namespace Graph {


class GraphManager {
private:

	const double margin = 100;
	double x, y, width, height;
	SP<Graph> graph;
	RectF viewerRect;
	RectF downButtonX, upButtonX, downButtonY, upButtonY;

public:

	GraphManager(double x, double y, double width, double height, SP<Function::AbstractFunction> function);

	void Update();
};


}
}