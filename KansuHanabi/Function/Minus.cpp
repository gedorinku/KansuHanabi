#include "Minus.h"
#include <assert.h>


hanabi::Minus::Minus(const Minus& obj)
	: Function(obj)
{
}

double hanabi::Minus::Evaluate(double x)
{
	assert(1 == innerFunctions.size());
	return -innerFunctions.front()->Evaluate(x);
}
