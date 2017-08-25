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

	void Update();

	Vec2 GetRate();

	void SetRate(const Vec2 &rate);

	double GetRateX();

	void SetRateX(double x);

	double GetRateY();

	void SetRateY(double y);

	Vec2 GetTranslation();

	void SetTranslation(const Vec2 &translation);

	double GetTranslationX();

	void SetTranslationX(double x);

	double GetTranslationY();

	void SetTranslationY(double y);
};


}
}