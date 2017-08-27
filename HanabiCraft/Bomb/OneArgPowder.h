#pragma once
#include "Util.h"
#include <vector>
#include "AbstractGunPowder.h"
#include "Function\IOneArgFunction.h"
#include "Function\AbstractFunction.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Bomb {


class OneArgPowder : public AbstractGunPowder, public Function::IOneArgFunction {
private:

	SP<Function::IOneArgFunction> function;
	SP<AbstractGunPowder> child;

	OneArgPowder(SP<Function::IOneArgFunction> function,
				 SP<AbstractGunPowder> child,
				 const Color &color);

	virtual double WeakEval(double x) override;

	virtual void update(const Circle &base) override;

public:

	static SP<OneArgPowder> Build(SP<Function::IOneArgFunction> function);

	// IOneArgFunction ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual SP<AbstractFunction> GetChild() override;
	virtual void SetChild(SP<AbstractFunction> child) override;
	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override;

	// AbstractGunPowder ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual SP<Function::AbstractFunction> GetFunction() override;

	// AbstractGunPowder ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual int ChildCount() override;
	virtual SP<AbstractGunPowder> GetChild(int index) override;
	virtual void SetChild(int index, SP<AbstractGunPowder> child) override;

	// AbstractGunPowder ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual Circle ChildCircle(const Circle &base, int index) override;

	// AbstractGunPowder ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void drawAll(const Circle & base) override;
};


}
}