#pragma once
#include <Util.h>
#include "AbstractGunPowder.h"
#include "Function\AbstractFunction.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
namespace Bomb {


class LeafXPowder : public AbstractGunPowder, public Function::AbstractFunction {
private:

	SP<Function::LeafX> function;

	virtual void update(const Circle &base) override;

public:

	LeafXPowder(SP<Function::LeafX> function);

	virtual std::vector<SP<AbstractFunction>> GetChildren() override;
	
	virtual void SetChilren(const std::vector<SP<AbstractFunction>>& children) override;
	
	virtual SP<AbstractFunction> Clone(const std::vector<SP<AbstractFunction>>& newChildren) override;
	
	virtual double WeakEval(double x) override;

	// AbstractGunPowder を介して継承されました
	virtual SP<Function::AbstractFunction> GetFunction() override;

	// AbstractGunPowder を介して継承されました
	virtual int ChildCount() override;
	virtual SP<AbstractGunPowder> GetChild(int index) override;
	virtual void SetChild(int index, SP<AbstractGunPowder> child) override;

	// AbstractGunPowder を介して継承されました
	virtual Circle ChildCircle(const Circle &base, int index) override;

	// AbstractGunPowder を介して継承されました
	virtual void drawAll(const Circle & base) override;
};


}
}