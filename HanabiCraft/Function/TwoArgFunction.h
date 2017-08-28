#pragma once
#include "AbstractFunction.h"

namespace HanabiCraft {
namespace Function {


class TwoArgFunction : public AbstractFunction {
public:

	virtual SP<AbstractFunction> GetChild1() = 0;

	virtual void SetChild1(SP<AbstractFunction> child1) = 0;

	virtual SP<AbstractFunction> GetChild2() = 0;

	virtual void SetChild2(SP<AbstractFunction> child2) = 0;

	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild1,
												 SP<Function::AbstractFunction> newChild2) = 0;

	void CheckChildren(const std::vector<SP<AbstractFunction>> &children) {
		if (children.size() != 2) throw "‚±‚ÌŠÖ”‚Ìˆø”‚Ì”‚Í2‚Å‚·";
	}

	void SetChilren(const std::vector<SP<Function::AbstractFunction>> &children) override {
		CheckChildren(children);
		SetChild1(children[0]);
		SetChild2(children[1]);
	}

	std::vector<SP<Function::AbstractFunction>> GetChildren() override { return {GetChild1(), GetChild2()}; }

	SP<Function::AbstractFunction> Clone(const std::vector<SP<Function::AbstractFunction>> &newChildren) override {
		CheckChildren(newChildren);
		return Clone(newChildren[0], newChildren[1]);
	}
};


}
}