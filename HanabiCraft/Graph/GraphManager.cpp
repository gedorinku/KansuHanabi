#include "GraphManager.h"

namespace HanabiCraft {
namespace Graph {


GraphManager::GraphManager(double x,
						   double y,
						   double width,
						   double height,
						   SP<Function::AbstractFunction> function)
	: x(x), y(y), width(width), height(height)
	, graph(new Graph(x + margin, y, width - margin, height - margin, function))
	, viewerRect(x + margin, y, width - margin, height - margin)
	, downButtonX(x + margin, y + height - margin, (width - margin)/2, margin)
	, upButtonX(x + margin + (width - margin)/2, y + height - margin, (width - margin)/2, margin)
	, downButtonY(x, y + (height - margin)/2, margin, (height - margin)/2)
	, upButtonY(x, y, margin, (height - margin)/2){

}

void GraphManager::Update() {
	const double rateOfRate = 1e-2;
	if (viewerRect.mouseOver) {
		if (Input::MouseL.pressed) {
			graph->Translate(Mouse::Delta());
		}
		if (Input::KeyUp.pressed) {
			graph->SetRate(graph->GetRate()*(1 + rateOfRate));
		}
		if (Input::KeyDown.pressed) {
			graph->SetRate(graph->GetRate()*(1 - rateOfRate));
		}
	}
	downButtonX.draw(HSV(0, 63, 331));
	upButtonX.draw(HSV(195, 63, 331));
	downButtonY.draw(HSV(0, 63, 331));
	upButtonY.draw(HSV(195, 63, 331));
	if (downButtonX.mouseOver && Input::MouseL.pressed) {
		graph->SetRateX(graph->GetRateX()*(1 - rateOfRate));
	}
	else if (upButtonX.mouseOver && Input::MouseL.pressed) {
		graph->SetRateX(graph->GetRateX()*(1 + rateOfRate));
	}
	else if (downButtonY.mouseOver && Input::MouseL.pressed) {
		graph->SetRateY(graph->GetRateY()*(1 - rateOfRate));
	}
	else if (upButtonY.mouseOver && Input::MouseL.pressed) {
		graph->SetRateY(graph->GetRateY()*(1 + rateOfRate));
	}
	graph->Update();
}


}
}