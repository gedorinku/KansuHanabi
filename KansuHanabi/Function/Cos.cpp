#include "Cos.h"
#include <cmath>


hanabi::Cos::Cos()
{
	innerFunctions.emplace_back(std::make_shared<Function>());
}


hanabi::Cos::~Cos()
{
}

double hanabi::Cos::Evaluate(double x)
{
	return std::cos(innerFunctions.front()->Evaluate(x));
}
