#pragma once
#include "Util.h"
#include "AbstractGunPowder.h"
#include "Function\AbstractFunction.h"
#include "Function\TwoArgFunction.h"

namespace HanabiCraft {
namespace Bomb {


class TwoArgPowder : public AbstractGunPowder {
private:

	SP<Function::TwoArgFunction> function;
	SP<AbstractGunPowder> child1, child2;
	double rad;

	TwoArgPowder(SP<Function::TwoArgFunction> function,
				 SP<AbstractGunPowder> child1,
				 SP<AbstractGunPowder> child2);

public:

	static SP<TwoArgPowder> Build(SP<Function::TwoArgFunction> function);

	// AbstractGunPowder ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void update(const Circle & base) override;

	virtual void drawAll(const Circle & base) override;

	virtual int ChildCount() override;

	virtual SP<AbstractGunPowder> GetChild(int index) override;

	virtual void SetChild(int index, SP<AbstractGunPowder> child) override;

	virtual SP<Function::AbstractFunction> GetFunction() override;

	virtual Circle ChildCircle(const Circle & base, int index) override;

};


}
}