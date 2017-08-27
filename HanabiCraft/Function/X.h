#pragma once
#include "IOneArgFunction.h"
#include "AbstractFunction.h"

namespace HanabiCraft {
namespace Function {


class X : public IOneArgFunction {
private:

	SP<AbstractFunction> child;

public:

	X(SP<AbstractFunction> child) : child(child) {}

	// IOneArgFunction ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual double WeakEval(double x) override { return x; }

	virtual SP<AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<AbstractFunction>(new X(newChild));
	}

};


}
}