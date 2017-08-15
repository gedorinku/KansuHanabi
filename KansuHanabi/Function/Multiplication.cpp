#include "Multiplication.h"
#include <assert.h>


hanabi::Multiplication::Multiplication(const Multiplication& obj)
	: Function(obj)
{
}

double hanabi::Multiplication::evaluate(double x) const
{
	assert(2 <= innerFunctions.size());
	auto result = 1.0;
	for (auto fun : innerFunctions)
	{
		result *= fun->evaluate(x);
	}

	return result;
}
