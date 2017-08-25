#pragma once
#include <Util.h>
#include "IGunPowder.h"
#include "Function\AbstractFunction.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
namespace BombViewer {


class LeafXPowder : public IGunPowder, public Function::AbstractFunction {
private:

	SP<Function::LeafX> function;

public:

	LeafXPowder(SP<Function::LeafX> function) : function(function) {}

	virtual void Update() override;

	virtual std::vector<SP<AbstractFunction>> GetChildren() override;
	
	virtual void SetChilren(const std::vector<SP<AbstractFunction>>& children) override;
	
	virtual SP<AbstractFunction> Clone(const std::vector<SP<AbstractFunction>>& newChildren) override;
	
	virtual double WeakEval(double x) override;

	virtual Vec2 GetPos() override;
	
	virtual double GetR() override;
};


}
}