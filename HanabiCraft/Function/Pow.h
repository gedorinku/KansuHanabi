#pragma once
#include "OneArgFunction.h"
#include "LeafX.h"
#include <cmath>

namespace HanabiCraft {
namespace Function {


template<int N>
class Pow : public OneArgFunction {
private:

	SP<Function::AbstractFunction> child;

public:

	static SP<Pow<N>> Build(SP<AbstractFunction> child) {
		return SP<Pow<N>>(new Pow<N>(child));
	}

	Pow(SP<Function::AbstractFunction> child) : child(child) {}

	virtual double WeakEval(double x) override {
		if (x == 0) return *(double*)nan;
		if (N == 0) {
			if (x == 0) return *(double*)nan;
			return 1;
		}
		if (N < 0) return 1/std::pow(child->Eval(x), -N);
		return std::pow(child->Eval(x), N);
	}

	virtual SP<Function::AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<Function::AbstractFunction>(new Pow<N>(newChild));
	}
};


}
}