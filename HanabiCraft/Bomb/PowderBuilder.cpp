#include "PowderBuilder.h"
#include "Function\IOneArgFunction.h"
#include "OneArgPowder.h"
#include "LeafXPowder.h"
#include "Function\LeafX.h"
#include "Function\TwoArgFunction.h"
#include "TwoArgPowder.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Bomb {


PowderBuilder::PowderBuilder(SP<AbstractFunction> function) : function(function) {}

//TODO: イカした設計とコード #とは
SP<AbstractGunPowder> PowderBuilder::Build() {
	{
		auto p = std::dynamic_pointer_cast<IOneArgFunction>(function);
		if (p) return OneArgPowder::Build(p);
	}
	{
		auto p = std::dynamic_pointer_cast<LeafX>(function);
		if (p) return SP<AbstractGunPowder>(new LeafXPowder(p));
	}
	{
		auto p = std::dynamic_pointer_cast<TwoArgFunction>(function);
		if (p) return TwoArgPowder::Build(p);
	}
	assert(false);
}


}
}