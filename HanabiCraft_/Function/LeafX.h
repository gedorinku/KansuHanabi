#pragma once
#include "Util.h"
#include "AbstractFunction.h"

namespace HanabiCraft {
namespace Function {


class LeafX sealed : public AbstractFunction {
public:

	virtual std::vector<SP<AbstractFunction>> GetChildren() override {
		return std::vector<SP<AbstractFunction>>();
	}

	virtual void SetChilren(const std::vector<SP<AbstractFunction>> &children) override {
		if (children.size() != 0) throw "vectorのサイズが正しくありません 0が期待されます";
	}

	virtual SP<AbstractFunction> Clone(const std::vector<SP<AbstractFunction>> &children) {
		if (children.size() != 0) throw "vectorのサイズが正しくありません 0が期待されます";
		return SP<AbstractFunction>(new LeafX());
	}

	virtual double WeakEval(double x) override { return x; }

};


}
}