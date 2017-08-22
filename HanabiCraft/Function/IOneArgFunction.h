#pragma once
#include "Util.h"
#include "IFunction.h"

namespace HanabiCraft {
namespace Function {


class IOneArgFunction : IFunction {
public:

	virtual SP<IFunction> GetArg() = 0;
};


}
}