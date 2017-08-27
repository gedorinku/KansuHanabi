#pragma once
#include "Util.h"
#include "Function\AbstractFunction.h"
#include "AbstractGunPowder.h"

namespace HanabiCraft {
namespace Bomb {


using namespace HanabiCraft::Function;
class PowderBuilder {
private:

	SP<AbstractFunction> function;

public:

	PowderBuilder(SP<AbstractFunction> function);

	SP<AbstractGunPowder> Build();
};


}
}