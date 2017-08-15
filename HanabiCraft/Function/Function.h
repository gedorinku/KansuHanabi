#pragma once
#include <vector>

namespace HanabiCraft {
namespace Function {


class Function {
protected:
	std::vector<Function> children;
	virtual double eval(const std::vector<double> &arg) = 0;
public:
	Function(const std::vector<Function> &children);
	double Eval(double x);

};


}
}