#include "Sin.h"
#include <cmath>


hanabi::Sin::Sin()
{
}

hanabi::Sin::Sin(const Sin& obj) : Function(obj)
{
}

hanabi::Sin::~Sin()
{
}

double hanabi::Sin::Evaluate(double x)
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->Evaluate(x);
	return std::sin(inner);
}
