#pragma once
#include "Util.h"
#include "Parent.h"

namespace HanabiCraft {
namespace Function {


class LeafX sealed : public IFunction {
public:

	virtual double Eval(double x) override { return x; }

};


}
}