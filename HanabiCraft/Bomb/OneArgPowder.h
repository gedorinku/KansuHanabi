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

	// IOneArgFunction ����Čp������܂���
	virtual SP<AbstractFunction> GetChild() override;
	virtual void SetChild(SP<AbstractFunction> child) override;
	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override;

	// AbstractGunPowder ����Čp������܂���
	virtual SP<Function::AbstractFunction> GetFunction() override;

	// AbstractGunPowder ����Čp������܂���
	virtual int ChildCount() override;
	virtual SP<AbstractGunPowder> GetChild(int index) override;
	virtual void SetChild(int index, SP<AbstractGunPowder> child) override;

	// AbstractGunPowder ����Čp������܂���
	virtual Circle ChildCircle(const Circle &base, int index) override;

	// AbstractGunPowder ����Čp������܂���
	virtual void drawAll(const Circle & base) override;
};


}
}