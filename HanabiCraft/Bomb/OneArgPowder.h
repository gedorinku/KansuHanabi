#pragma once
#include "Util.h"
#include <vector>
#include "AbstractGunPowder.h"
#include "Function\OneArgFunction.h"
#include "Function\AbstractFunction.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Bomb {


class OneArgPowder : public AbstractGunPowder {
private:

	SP<Function::OneArgFunction> function;
	SP<AbstractGunPowder> child;

	OneArgPowder(SP<Function::OneArgFunction> function, SP<AbstractGunPowder> child);

	//virtual double WeakEval(double x) override;

	virtual void update(const Circle &base) override;

public:

	static SP<OneArgPowder> Build(SP<Function::OneArgFunction> function);

	// IOneArgFunction を介して継承されました
	//virtual SP<AbstractFunction> GetChild() override;
	//virtual void SetChild(SP<AbstractFunction> child) override;
	//virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override;

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