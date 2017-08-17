#include "Sin.h"
#include <cmath>
#include <cassert>


hanabi::Sin::Sin(const Sin & obj)
	: Function(obj)
{
}

double hanabi::Sin::evaluate(double x) const
{
	assert(innerFunctions.size() <= 1);
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->evaluate(x);
	return std::sin(inner);
}
