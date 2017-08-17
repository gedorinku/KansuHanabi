#include <memory>
#include <assert.h>
#include "Fraction.h"


hanabi::Fraction::Fraction(const Function & numerator, const Function & denominator)
{
	innerFunctions.emplace_back(std::make_shared<Function>(numerator));
	innerFunctions.emplace_back(std::make_shared<Function>(denominator));
}

double hanabi::Fraction::evaluate(double x) const
{
	assert(2 <= innerFunctions.size());
	auto it = innerFunctions.begin();
	auto result = (*it)->evaluate(x);
	for (; it != innerFunctions.end(); ++it)
	{
		result /= (*it)->evaluate(x);
	}
	return result;
}
