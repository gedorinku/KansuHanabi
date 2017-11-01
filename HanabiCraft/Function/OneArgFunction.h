#pragma once
#include "Util.h"
#include "AbstractFunction.h"

namespace HanabiCraft {
namespace Function {


class OneArgFunction : public AbstractFunction {
public:

	virtual SP<AbstractFunction> GetChild() = 0;

	virtual void SetChild(SP<AbstractFunction> child) = 0;

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) = 0;

	void CheckChildren(const std::vector<SP<AbstractFunction>> &children) {
		if (children.size() != 1) throw "‚±‚ÌŠÖ”‚Ìˆø”‚Ì”‚Í1‚Å‚·";
	}

	void SetChilren(const std::vector<SP<Function::AbstractFunction>> &children) override {
		CheckChildren(children);
		SetChild(children[0]);
	}

	std::vector<SP<Function::AbstractFunction>> GetChildren() override { return {GetChild()}; }

	SP<Function::AbstractFunction> Clone(const std::vector<SP<Function::AbstractFunction>> &newChildren) override {
		CheckChildren(newChildren);
		return Clone(newChildren[0]);
	}
};


}
}