#include "Cos.h"
#include <cmath>


hanabi::Cos::Cos()
{
}


hanabi::Cos::~Cos()
{
}

double hanabi::Cos::Evaluate(double x)
{
	auto inner = innerFunctions.empty() ? x : innerFunctions.front()->Evaluate(x);
	return std::cos(inner);
}
