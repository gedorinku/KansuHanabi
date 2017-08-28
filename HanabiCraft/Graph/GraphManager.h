#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Graph.h"
#include "Function\AbstractFunction.h"

namespace HanabiCraft {
namespace Graph {


class GraphManager {
private:

	double margin = 100;
	double x, y, width, height;
	SP<Graph> graph;
	RectF viewerRect;
	RectF downButtonX, upButtonX, downButtonY, upButtonY;
	const Texture downXTex, upXTex, downYTex, upYTex;

public:

	GraphManager(double x, double y, double width, double height, SP<Function::AbstractFunction> function, int aaaaaa = -1);

	void SetFunction(SP<Function::AbstractFunction> function);

	void Update();

	void Draw();
};


}
}