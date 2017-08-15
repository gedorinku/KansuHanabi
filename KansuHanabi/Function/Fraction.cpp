#include "Fraction.h"
#include <assert.h>


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
