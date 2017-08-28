#include "GraphManager.h"

namespace HanabiCraft {
namespace Graph {


//marginの初期化を早めにやってほしいんですけど、コンストラクタの呼ばれる順が変数の宣言順？(注意)
GraphManager::GraphManager(double x,
						   double y,
						   double width,
						   double height,
						   SP<Function::AbstractFunction> function)
	: x(x), y(y), width(width), height(height)
	, margin(Min(width, height)*0.2)
	, graph(new Graph(x + margin, y, width - margin, height - margin, function))
	, viewerRect(x + margin, y, width - margin, height - margin)
	, downButtonX(x + margin, y + height - margin, (width - margin)/2, margin)
	, upButtonX(x + margin + (width - margin)/2, y + height - margin, (width - margin)/2, margin)
	, downButtonY(x, y + (height - margin)/2, margin, (height - margin)/2)
	, upButtonY(x, y, margin, (height - margin)/2){

}

void GraphManager::SetFunction(SP<Function::AbstractFunction> function) {
	graph->SetFunction(function);
}

void GraphManager::Update() {
	const double rateOfRate = 1e-2;
	if (viewerRect.mouseOver) {
		if (Input::MouseL.pressed) {
			graph->Translate(Mouse::DeltaF());
		}
		if (Input::KeyUp.pressed) {
			graph->SetRate(graph->GetRate()*(1 + rateOfRate));
		}
		if (Input::KeyDown.pressed) {
			graph->SetRate(graph->GetRate()*(1 - rateOfRate));
		}
	}
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
}

void GraphManager::Draw() {
	downButtonX.draw(HSV(0, 0.63, 0.8));
	upButtonX.draw(HSV(195, 0.63, 0.8));
	downButtonY.draw(HSV(0, 0.63, 0.8));
	upButtonY.draw(HSV(195, 0.63, 0.8));
	graph->Draw();
}


}
}