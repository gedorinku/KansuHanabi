#include "Multiplication.h"
#include <assert.h>


hanabi::Multiplication::Multiplication(const Multiplication& obj)
	: Function(obj)
{
}

double hanabi::Multiplication::Evaluate(double x)
{
	assert(2 <= innerFunctions.size());
	auto result = 1.0;
	for (auto fun : innerFunctions)
	{
		result *= fun->Evaluate(x);
	}

	return result;
}
