#pragma once
#include "Util.h"
#include <vector>
#include "IGunPowder.h"
#include "Function\IOneArgFunction.h"
#include "Function\IFunction.h"

namespace HanabiCraft {
namespace BombViewer {


class OneArgPowder : IGunPowder {
private:

	std::vector<SP<IGunPowder>> children;

	OneArgPowder(const std::vector<SP<IGunPowder>> &children);

public:

	static SP<OneArgPowder> Build(SP<IOneArgFunction> function);

	virtual std::vector<SP<Function::IFunction>> GetChildren() override;

	virtual void SetChilren(const std::vector<SP<Function::IFunction>>& children) override;

	virtual void Update() override;

	virtual double Eval(double x) override;
};


}
}