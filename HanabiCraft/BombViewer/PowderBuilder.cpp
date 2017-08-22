#include "PowderBuilder.h"
#include "Function\IOneArgFunction.h"
#include "OneArgPowder.h"

namespace HanabiCraft {
namespace BombViewer {


PowderBuilder::PowderBuilder(SP<IFunction> function) : function(function) {}

SP<IGunPowder> PowderBuilder::Build() {
	const type_info &type = typeid(*function);
	if (type == typeid(IOneArgFunction))
		return SP<IGunPowder>(new OneArgPowder(function));
	assert(false);
}


}
}