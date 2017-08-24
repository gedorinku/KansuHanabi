#pragma once
#include "IOneArgFunction.h"

namespace HanabiCraft {
namespace Function {


class Sin : public IOneArgFunction {
private:

	SP<Function::IFunction> child;

public:

	Sin(SP<Function::IFunction> child) : child(child) {}

	virtual SP<Function::IFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::IFunction> child) override { this->child = child; }

	virtual double Eval(double x) { return sin(x); }

	virtual SP<Function::IFunction> Clone(SP<Function::IFunction> newChild) override {
		return SP<Function::IFunction>(new Sin(newChild));
	}
};


}
}