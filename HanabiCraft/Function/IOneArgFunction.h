#pragma once
#include "Util.h"
#include "IFunction.h"

namespace HanabiCraft {
namespace Function {


class IOneArgFunction : public IFunction {
public:

	virtual SP<IFunction> GetChild() = 0;

	virtual void SetChild(SP<IFunction> child) = 0;

	virtual SP<Function::IFunction> Clone(SP<Function::IFunction> newChild) = 0;

	void CheckChildren(const std::vector<SP<IFunction>> &children) {
		if (children.size() != 1) throw "‚±‚ÌŠÖ”‚Ìˆø”‚Ì”‚Í1‚Å‚·";
	}

	void SetChilren(const std::vector<SP<Function::IFunction>> &children) override {
		CheckChildren(children);
		SetChild(children[0]);
	}

	std::vector<SP<Function::IFunction>> GetChildren() override { return {GetChild()}; }

	SP<Function::IFunction> Clone(const std::vector<SP<Function::IFunction>> &newChildren) override {
		CheckChildren(newChildren);
		return Clone(newChildren[0]);
	}
};


}
}