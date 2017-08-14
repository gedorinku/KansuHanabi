#include "Cos.h"
#include <cmath>


double hanabi::Cos::Evaluate(double x)
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->Evaluate(x);
	return std::cos(inner);
}
