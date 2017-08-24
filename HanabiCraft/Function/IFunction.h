#pragma once
#include "Util.h"
#include <vector>

namespace HanabiCraft {
namespace Function {


class IFunction {
public:

	virtual std::vector<SP<IFunction>> GetChildren() = 0;

	virtual void SetChilren(const std::vector<SP<IFunction>> &children) = 0;

	virtual SP<IFunction> Clone(const std::vector<SP<IFunction>> &newChildren) = 0;

	virtual double Eval(double x) = 0;
};


}
}