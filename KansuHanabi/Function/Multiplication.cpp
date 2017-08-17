#include "Multiplication.h"
#include <assert.h>


hanabi::Multiplication::Multiplication(const Multiplication& obj)
	: Function(obj)
{
}

hanabi::Multiplication::Multiplication(const Function & function1, const Function & function2)
{
	innerFunctions.emplace_back(std::make_shared<Function>(function1));
	innerFunctions.emplace_back(std::make_shared<Function>(function2));
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
