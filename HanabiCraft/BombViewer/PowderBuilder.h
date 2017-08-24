#pragma once
#include "Util.h"
#include "Function\IFunction.h"
#include "IGunPowder.h"

namespace HanabiCraft {
namespace BombViewer {


using namespace HanabiCraft::Function;
class PowderBuilder {
private:

	SP<IFunction> function;

public:

	PowderBuilder(SP<IFunction> function);

	SP<IGunPowder> Build(const Vec2 &pos, double r);
};


}
}