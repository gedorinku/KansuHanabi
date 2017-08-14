#include "Fraction.h"
#include <assert.h>


double hanabi::Fraction::Evaluate(double x)
{
	assert(2 <= innerFunctions.size());
	auto it = innerFunctions.begin();
	auto result = (*it)->Evaluate(x);
	for (; it != innerFunctions.end(); ++it)
	{
		result /= (*it)->Evaluate(x);
	}
	return result;
}
