#include "Graph.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Graph {


Graph::Graph(double x, double y, double width, double height, SP<Function::AbstractFunction> function)
	: x(x), y(y), width(width), height(height), function(function) {
	function->SetRate({0.05, 1});
}

void Graph::Update() {
	Rect(x, y, width, height).draw(Palette::White);
	int div = width + 0.5;
	for (int i = 0; i < div; i++) {
		Vec2 a(i/(double)div, 0.5 - function->Eval(i*2/(double)div - 1)/2);
		Vec2 b((i + 1)/(double)div, 0.5 - function->Eval((i + 1)*2/(double)div - 1)/2);
		a.x *= width; a.y *= height;
		b.x *= width; b.y *= height;
		Line(a, b).draw(1, Palette::Blue);
	}
	Line(x, y + height/2, x + width, y + height/2).draw(2, Palette::Black);
	Line(x + width/2, y, x + width/2, y + height).draw(2, Palette::Black);
}

Vec2 Graph::GetRate() { return function->GetRate(); }

void Graph::SetRate(const Vec2 & rate) { function->SetRate(rate); }

double Graph::GetRateX() { return function->GetRateX(); }

void Graph::SetRateX(double x) { function->SetRateX(x); }

double Graph::GetRateY() { return function->GetRateY(); }

void Graph::SetRateY(double y) { function->SetRateY(y); }

Vec2 Graph::GetTranslation() { return function->GetTranslation(); }

void Graph::SetTranslation(const Vec2 & translation) { return function->SetTranslation(translation); }

double Graph::GetTranslationX() { return function->GetTranslationX(); }

void Graph::SetTranslationX(double x) { function->SetTranslationX(x); }

double Graph::GetTranslationY() { return function->GetTranslationY(); }

void Graph::SetTranslationY(double y) { function->SetTranslationY(y); }


}
}