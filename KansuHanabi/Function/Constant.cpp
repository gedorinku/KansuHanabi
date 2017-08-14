#include "Constant.h"



hanabi::Constant::Constant(double value) : value(value)
{
}

hanabi::Constant::Constant(const Constant& obj) : Function(obj), value(obj.value)
{
}

double hanabi::Constant::Evaluate(double x)
{
	return value;
}
