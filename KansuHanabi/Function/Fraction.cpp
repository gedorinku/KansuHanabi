#include <memory>
#include <assert.h>
#include "Fraction.h"

double hanabi::Fraction::evaluate(double x) const
{
	assert(2 <= innerFunctions.size());
	auto it = innerFunctions.begin();
	auto result = (*it)->evaluate(x);
	it++;
	for (; it != innerFunctions.end(); ++it)
	{
		result /= (*it)->evaluate(x);
	}
	return result;
}
