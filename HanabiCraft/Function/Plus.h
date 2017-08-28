#pragma once
#include "Util.h"
#include "AbstractFunction.h"
#include "TwoArgFunction.h"

namespace HanabiCraft {
namespace Function {


class Plus : public TwoArgFunction {
private:

	SP<AbstractFunction> child1, child2;

public:

	Plus(SP<AbstractFunction> child1, SP<AbstractFunction> child2)
		: child1(child1), child2(child2) {}

	virtual double WeakEval(double x) override {
		return child1->Eval(x) + child2->Eval(x);
	}

	virtual SP<AbstractFunction> GetChild1() override { return child1; }

	virtual void SetChild1(SP<AbstractFunction> child1) override { this->child1 = child1; }

	virtual SP<AbstractFunction> GetChild2() override { return child2; }

	virtual void SetChild2(SP<AbstractFunction> child2) override { this->child2 = child2; }

	virtual SP<AbstractFunction> Clone(SP<AbstractFunction> newChild1,
									   SP<AbstractFunction> newChild2) override {
		return SP<AbstractFunction>(new Plus(newChild1, newChild2));
	}
};


}
}