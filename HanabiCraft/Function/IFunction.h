#pragma once

namespace HanabiCraft {
namespace Function {


class IFunction {
public:

	virtual double Eval(double x) = 0;
};


}
}