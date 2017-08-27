#pragma once
#include "Util.h"
#include "Function\AbstractFunction.h"
#include "IGunPowder.h"

namespace HanabiCraft {
namespace BombViewer {


using namespace HanabiCraft::Function;
class PowderBuilder {
private:

	SP<AbstractFunction> function;

public:

	PowderBuilder(SP<AbstractFunction> function);

	SP<IGunPowder> Build(const Vec2 &pos, double r);
};


}
}