#pragma once
#include "Util.h"
#include "IFunction.h"
#include <vector>

namespace HanabiCraft {
namespace Function {


//Derived: IFunction‚ðŽÀ‘•
template<class Derived>
class Parent : public IFunction {
private:

	std::vector<SP<Derived>> children;

	virtual double eval(const std::vector<double> &args) = 0;

public:

	Parent(const std::vector<SP<Derived>> &children) : children(children) {}

	//T: IFunction‚ðŽÀ‘•
	template<class T> Parent(const Parent<T> &source, const std::vector<SP<Derived>> &newChildren)
		: children(newChildren) {}

	virtual double Eval(double x) override {
		std::vector<double> args;
		for each (SP<Derived> var in children) {
			args.push_back(var->Eval(x));
		}
		return eval(args);
	}
};


}
}