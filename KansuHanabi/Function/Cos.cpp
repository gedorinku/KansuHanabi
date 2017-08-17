#include "Cos.h"
#include <cmath>
#include <cassert>


hanabi::Cos::Cos(const Cos & obj)
	: Function(obj)
{
}

double hanabi::Cos::evaluate(double x) const
{
	assert(innerFunctions.size() <= 1);
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->evaluate(x);
	return std::cos(inner);
}
