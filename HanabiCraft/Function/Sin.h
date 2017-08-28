#pragma once
#include "IOneArgFunction.h"
#include "LeafX.h"

namespace HanabiCraft {
namespace Function {


class Sin : public IOneArgFunction {
private:

	SP<Function::AbstractFunction> child;

public:

	Sin(SP<Function::AbstractFunction> child = SP<AbstractFunction>(new LeafX())) : child(child) {}

	virtual double WeakEval(double x) override { return sin(child->Eval(x)); }

	virtual SP<Function::AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<Function::AbstractFunction>(new Sin(newChild));
	}
};


}
}