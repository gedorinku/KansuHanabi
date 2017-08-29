#pragma once
#include "IOneArgFunction.h"
#include "AbstractFunction.h"

namespace HanabiCraft {
namespace Function {


class X : public IOneArgFunction {
private:

	SP<AbstractFunction> child;

public:

	static SP<X> Build(SP<AbstractFunction> child) {
		return SP<X>(new X(child));
	}

	X(SP<AbstractFunction> child) : child(child) {}

	// IOneArgFunction ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual double WeakEval(double x) override { return child->Eval(x); }

	virtual SP<AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<AbstractFunction>(new X(newChild));
	}

};


}
}