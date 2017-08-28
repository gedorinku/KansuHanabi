#pragma once
#include "Util.h"
#include "Function\AbstractFunction.h"

namespace HanabiCraft {
namespace Graph {


class Graph {
private:
	
	double x, y, width, height;
	
	SP<Function::AbstractFunction> function;

public:

	Graph(double x, double y, double width, double height, SP<Function::AbstractFunction> function);

	void Draw();

	double ActualX();

	double ActualY();

	double ActualWidth();

	double ActualHeight();

	void SetFunction(SP<Function::AbstractFunction> function);

	Vec2 GetRate();

	void SetRate(const Vec2 &rate);

	double GetRateX();

	void SetRateX(double x);

	double GetRateY();

	void SetRateY(double y);

	Vec2 GetTranslation();

	void Translate(const Vec2 &delta);
};


}
}