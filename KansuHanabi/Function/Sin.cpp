#include "Sin.h"
#include <cmath>


double hanabi::Sin::evaluate(double x) const
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->evaluate(x);
	return std::sin(inner);
}
