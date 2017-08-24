#pragma once
#include "Util.h"
#include <vector>
#include "IGunPowder.h"
#include "Function\IOneArgFunction.h"
#include "Function\IFunction.h"
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

public:

	static SP<OneArgPowder> Build(const Vec2 &pos, double r, SP<Function::IOneArgFunction> function);

	virtual void Update() override;

	virtual double Eval(double x) override;

	// IOneArgFunction ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual SP<IFunction> GetChild() override;
	virtual void SetChild(SP<IFunction> child) override;
	virtual SP<Function::IFunction> Clone(SP<Function::IFunction> newChild) override;

	// IGunPowder ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual Vec2 GetPos() override;
	virtual double GetR() override;
};


}
}