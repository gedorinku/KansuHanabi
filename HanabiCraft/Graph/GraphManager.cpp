#include "GraphManager.h"

namespace HanabiCraft {
namespace Graph {


//marginの初期化を早めにやってほしいんですけど、コンストラクタの呼ばれる順が変数の宣言順？(注意)
GraphManager::GraphManager(double x,
						   double y,
						   double width,
						   double height,
						   SP<Function::AbstractFunction> function,
						   int aaaaaa)
	: x(x), y(y), width(width), height(height)
	, margin(Min(width, height)*0.2)
	, graph(new Graph(x + margin, y, width - margin, height - margin, function))
	, viewerRect(x + margin, y, width - margin, height - margin)
	, downButtonX(x + margin, y + height - margin, (width - margin)/2, margin)
	, upButtonX(x + margin + (width - margin)/2, y + height - margin, (width - margin)/2, margin)
	, downButtonY(x, y + (height - margin)/2, margin, (height - margin)/2)
	, upButtonY(x, y, margin, (height - margin)/2)
	, downYTex(L"Hanabi-assets/vert_zoomout.png")
	, upYTex(L"Hanabi-assets/vert_zooomin.png")
	, downXTex(L"Hanabi-assets/horz_zoomout.png")
	, upXTex(L"Hanabi-assets/horz_zoomin.png"){
	//左上
	if (aaaaaa == 0) {
		graph = SP<Graph>(new Graph(796*_UTIL_KUSOCONST,
									17*_UTIL_KUSOCONST,
									195*_UTIL_KUSOCONST,
									188*_UTIL_KUSOCONST,
									function));
		viewerRect = RectF(796*_UTIL_KUSOCONST,
						   17*_UTIL_KUSOCONST,
						   195*_UTIL_KUSOCONST,
						   188*_UTIL_KUSOCONST);
		downButtonY = RectF(747*_UTIL_KUSOCONST,
							109*_UTIL_KUSOCONST,
							downYTex.width*_UTIL_KUSOCONST,
							downYTex.height*_UTIL_KUSOCONST);
		upButtonY = RectF(747*_UTIL_KUSOCONST,
						  11*_UTIL_KUSOCONST,
						  upYTex.width*_UTIL_KUSOCONST,
						  upYTex.height*_UTIL_KUSOCONST);
		upButtonX = RectF(894*_UTIL_KUSOCONST,
							210*_UTIL_KUSOCONST,
							upXTex.width*_UTIL_KUSOCONST,
							upXTex.height*_UTIL_KUSOCONST);
		downButtonX = RectF(792*_UTIL_KUSOCONST,
						  210*_UTIL_KUSOCONST,
						  downXTex.width*_UTIL_KUSOCONST,
						  downXTex.height*_UTIL_KUSOCONST);
	}
	else if (aaaaaa == 1) {
		graph = SP<Graph>(new Graph(1065*_UTIL_KUSOCONST,
									17*_UTIL_KUSOCONST,
									195*_UTIL_KUSOCONST,
									188*_UTIL_KUSOCONST,
									function));
		viewerRect = RectF(1065*_UTIL_KUSOCONST,
						   17*_UTIL_KUSOCONST,
						   195*_UTIL_KUSOCONST,
						   188*_UTIL_KUSOCONST);
		downButtonY = RectF((747 + 269)*_UTIL_KUSOCONST,
							109*_UTIL_KUSOCONST,
							downYTex.width*_UTIL_KUSOCONST,
							downYTex.height*_UTIL_KUSOCONST);
		upButtonY = RectF((747 + 269)*_UTIL_KUSOCONST,
						  11*_UTIL_KUSOCONST,
						  upYTex.width*_UTIL_KUSOCONST,
						  upYTex.height*_UTIL_KUSOCONST);
		upButtonX = RectF((894 + 269)*_UTIL_KUSOCONST,
							210*_UTIL_KUSOCONST,
							upXTex.width*_UTIL_KUSOCONST,
							upXTex.height*_UTIL_KUSOCONST);
		downButtonX = RectF((792 + 269)*_UTIL_KUSOCONST,
						  210*_UTIL_KUSOCONST,
						  downXTex.width*_UTIL_KUSOCONST,
						  downXTex.height*_UTIL_KUSOCONST);
	}
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
	upButtonX(upXTex).draw();
	downButtonX(downXTex).draw();
	upButtonY(upYTex).draw();
	downButtonY(downYTex).draw();
	graph->Draw();
}


}
}