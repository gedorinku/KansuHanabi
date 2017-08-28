#include "Graph.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Graph {


Graph::Graph(double x, double y, double width, double height, SP<Function::AbstractFunction> function)
	: x(x), y(y), width(width), height(height), function(function) {
}

void Graph::Draw() {
	RasterizerState rasterizer = RasterizerState::Default2D;
	rasterizer.scissorEnable = true;
	Graphics2D::SetRasterizerState(rasterizer);
	Graphics2D::SetScissorRect(Rect(x + 0.5, y + 0.5, width + 0.5, height + 0.5));
	int div = width + 0.5;
	for (int i = 0; i < div; i++) {
		Vec2 a(i/(double)div, 0.5 - function->Eval(i*2/(double)div - 1)/2);
		Vec2 b((i + 1)/(double)div, 0.5 - function->Eval((i + 1)*2/(double)div - 1)/2);
		a.x = x + a.x*width; a.y = y + a.y*height;
		b.x = x + b.x*width; b.y = y + b.y*height;
		Line(a, b).draw(1, Palette::Blue);
	}
	Line(x, y + height/2, x + width, y + height/2).draw(2, Palette::Black);
	Line(x + width/2, y, x + width/2, y + height).draw(2, Palette::Black);
	Graphics2D::SetRasterizerState(RasterizerState::Default2D);
}

double Graph::ActualX() { return x; }

double Graph::ActualY() { return y; }

double Graph::ActualWidth() { return width; }

double Graph::ActualHeight() { return height; }

void Graph::SetFunction(SP<Function::AbstractFunction> function) {
	this->function = function;
}

Vec2 Graph::GetRate() { return function->GetRate(); }

void Graph::SetRate(const Vec2 & rate) { function->SetRate(rate); }

double Graph::GetRateX() { return function->GetRateX(); }

void Graph::SetRateX(double x) { function->SetRateX(x); }

double Graph::GetRateY() { return function->GetRateY(); }

void Graph::SetRateY(double y) { function->SetRateY(y); }

Vec2 Graph::GetTranslation() { return function->GetTranslation(); }

void Graph::Translate(const Vec2 &delta) {
	function->Translate(Vec2(delta.x*2/width, -delta.y*2/height));
}


}
}