#pragma once
#include <Util.h>
#include "IGunPowder.h"
#include "Function\IFunction.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
namespace BombViewer {


class LeafXPowder : public IGunPowder, public Function::IFunction {
private:

	SP<Function::LeafX> function;

public:

	LeafXPowder(SP<Function::LeafX> function) : function(function) {}

	virtual void Update() override;

	virtual std::vector<SP<IFunction>> GetChildren() override;
	
	virtual void SetChilren(const std::vector<SP<IFunction>>& children) override;
	
	virtual SP<IFunction> Clone(const std::vector<SP<IFunction>>& newChildren) override;
	
	virtual double Eval(double x) override;

	virtual Vec2 GetPos() override;
	
	virtual double GetR() override;
};


}
}