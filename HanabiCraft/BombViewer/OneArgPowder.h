#pragma once
#include "Util.h"
#include <vector>
#include "IGunPowder.h"
#include "Function\IOneArgFunction.h"
#include "Function\AbstractFunction.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace BombViewer {


class OneArgPowder : public IGunPowder, public Function::IOneArgFunction {
private:

	Vec2 pos;
	double r;
	SP<Function::IOneArgFunction> function;
	SP<IGunPowder> child;

	OneArgPowder(const Vec2 &pos,
				 double r,
				 SP<Function::IOneArgFunction> function,
				 SP<IGunPowder> child);

	virtual double WeakEval(double x) override;

public:

	static SP<OneArgPowder> Build(const Vec2 &pos, double r, SP<Function::IOneArgFunction> function);

	virtual void Update() override;

	// IOneArgFunction ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual SP<AbstractFunction> GetChild() override;
	virtual void SetChild(SP<AbstractFunction> child) override;
	virtual SP<Function::AbstractFunction> Clone(SP<Function::AbstractFunction> newChild) override;

	// IGunPowder ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Vec2 GetPos() override;
	virtual double GetR() override;
};


}
}