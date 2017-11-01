#pragma once
#include "OneArgFunction.h"
#include "LeafX.h"
#include <cmath>

namespace HanabiCraft {
namespace Function {


class Log : public OneArgFunction {
private:

	SP<Function::AbstractFunction> child;

public:

	static SP<Log> Build(SP<AbstractFunction> child) {
		return SP<Log>(new Log(child));
	}

	Log(SP<Function::AbstractFunction> child = SP<AbstractFunction>(new LeafX())) : child(child) {}

	virtual double WeakEval(double x) override { return std::log(child->Eval(x)); }

	virtual SP<Function::AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<Function::AbstractFunction>(new Log(newChild));
	}
};


}
}