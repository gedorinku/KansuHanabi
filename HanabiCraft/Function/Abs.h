#pragma once
#include "OneArgFunction.h"
#include "LeafX.h"
#include <cmath>

namespace HanabiCraft {
namespace Function {


class Abs : public OneArgFunction {
private:

	SP<Function::AbstractFunction> child;

public:

	static SP<Abs> Build(SP<AbstractFunction> child) {
		return SP<Abs>(new Abs(child));
	}

	Abs(SP<Function::AbstractFunction> child) : child(child) {}

	virtual double WeakEval(double x) override { return std::abs(child->Eval(x)); }

	virtual SP<Function::AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<Function::AbstractFunction>(new Abs(newChild));
	}
};


}
}