#include "Minus.h"
#include <assert.h>


hanabi::Minus::Minus(const Minus& obj)
	: Function(obj)
{
}

double hanabi::Minus::evaluate(double x) const
{
	assert(1 == innerFunctions.size());
	return -innerFunctions.front()->evaluate(x);
}
