#include "Cos.h"
#include <cmath>


double hanabi::Cos::evaluate(double x) const
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->evaluate(x);
	return std::cos(inner);
}
