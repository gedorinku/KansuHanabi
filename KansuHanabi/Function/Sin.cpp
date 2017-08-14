#include "Sin.h"
#include <cmath>


hanabi::Sin::Sin()
{
	innerFunctions.emplace_back(std::make_shared<Function>());
}

hanabi::Sin::Sin(const Sin& obj) : Function(obj)
{
}

hanabi::Sin::~Sin()
{
}

double hanabi::Sin::Evaluate(double x)
{
	return std::sin(innerFunctions.front()->Evaluate(x));
}
