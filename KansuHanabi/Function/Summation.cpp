#include "Summation.h"
#include <assert.h>


hanabi::Summation::Summation(const Summation& obj)
	: Function(obj)
{
}

double hanabi::Summation::evaluate(double x) const
{
	assert(2 <= innerFunctions.size());
	auto result = 0.0;
	for (auto fun : innerFunctions)
	{
		result += fun->evaluate(x);
	}

	return result;
}
