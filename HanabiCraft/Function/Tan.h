#pragma once
#include "OneArgFunction.h"
#include "LeafX.h"
#include <cmath>
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Function {


class Tan : public OneArgFunction {
private:

	SP<Function::AbstractFunction> child;

public:

	static SP<Tan> Build(SP<AbstractFunction> child) {
		return SP<Tan>(new Tan(child));
	}

	Tan(SP<Function::AbstractFunction> child = SP<AbstractFunction>(new LeafX())) : child(child) {}

	virtual double WeakEval(double x) override { return std::tan(child->Eval(x*2*Pi)); }

	virtual SP<Function::AbstractFunction> GetChild() override { return child; }

	virtual void SetChild(SP<Function::AbstractFunction> child) override { this->child = child; }

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override {
		return SP<Function::AbstractFunction>(new Tan(newChild));
	}
};


}
}