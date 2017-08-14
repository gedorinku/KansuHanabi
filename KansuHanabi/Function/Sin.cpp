#include "Sin.h"
#include <cmath>


double hanabi::Sin::Evaluate(double x)
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->Evaluate(x);
	return std::sin(inner);
}
