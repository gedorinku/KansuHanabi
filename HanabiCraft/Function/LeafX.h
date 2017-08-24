#pragma once
#include "Util.h"
#include "IFunction.h"

namespace HanabiCraft {
namespace Function {


class LeafX sealed : public IFunction {
public:

	virtual std::vector<SP<IFunction>> GetChildren() override {
		return std::vector<SP<IFunction>>();
	}

	virtual void SetChilren(const std::vector<SP<IFunction>> &children) override {
		if (children.size() != 0) throw "vector�̃T�C�Y������������܂��� 0�����҂���܂�";
	}

	virtual SP<IFunction> Clone(const std::vector<SP<IFunction>> &children) {
		if (children.size() != 0) throw "vector�̃T�C�Y������������܂��� 0�����҂���܂�";
		return SP<IFunction>(new LeafX());
	}

	virtual double Eval(double x) override { return x; }

};


}
}