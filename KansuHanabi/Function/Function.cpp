#include "Function.h"



hanabi::Function::Function(const Function & function)
	: innerFunctions(function.innerFunctions)
{
}

double hanabi::Function::evaluate(double x) const
{
	return x;
}

hanabi::Function hanabi::Function::X = hanabi::Function();
