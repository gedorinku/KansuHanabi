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
		if (children.size() != 0) throw "vector�̃T�C�Y������������܂��� 0�����҂���܂�";
	}

	virtual SP<AbstractFunction> Clone(const std::vector<SP<AbstractFunction>> &children) {
		if (children.size() != 0) throw "vector�̃T�C�Y������������܂��� 0�����҂���܂�";
		return SP<AbstractFunction>(new LeafX());
	}

	virtual double WeakEval(double x) override { return x; }

};


}
}