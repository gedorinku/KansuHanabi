#include "GraphManager.h"

namespace HanabiCraft {
namespace Graph {


GraphManager::GraphManager(double x,
						   double y,
						   double width,
						   double height,
						   SP<Function::AbstractFunction> function)
	: x(x), y(y), width(width), height(height)
	, graph(new Graph(x + margin, y + margin, width - margin, height - margin, function)) {
	
}

void GraphManager::Update() {
	Rect viewer(graph->ActualX(), graph->ActualY(), graph->ActualWidth(), graph->ActualHeight());
	if (viewer.mouseOver && Input::MouseL.pressed) {
		graph->Translate(Mouse::Delta());
	}
	graph->Update();
}


}
}