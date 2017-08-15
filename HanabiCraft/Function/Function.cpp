#include "Function.h"

namespace HanabiCraft {
namespace Function {


Function::Function(const std::vector<Function>& children) : children(children) {}
double Function::Eval(double x) {
	if (children.size() == 0) return x;
	std::vector<double> arg(children.size());
	for (int i = 0; i < children.size(); i++)
		arg[i] = children[i].Eval(x);
	return eval(arg);
}


}
}