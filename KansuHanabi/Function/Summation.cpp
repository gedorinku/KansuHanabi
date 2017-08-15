#include "Summation.h"
#include <assert.h>


hanabi::Summation::Summation(const Summation& obj)
	: Function(obj)
{
}

double hanabi::Summation::Evaluate(double x)
{
	assert(2 <= innerFunctions.size());
	auto result = 0.0;
	for (auto fun : innerFunctions)
	{
		result += fun->Evaluate(x);
	}

	return result;
}
