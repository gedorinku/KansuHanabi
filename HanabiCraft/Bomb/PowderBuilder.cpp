#include "PowderBuilder.h"
#include "Function\IOneArgFunction.h"
#include "OneArgPowder.h"
#include "LeafXPowder.h"
#include "Function\LeafX.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Bomb {


PowderBuilder::PowderBuilder(SP<AbstractFunction> function) : function(function) {}

//TODO: �C�J�����݌v�ƃR�[�h #�Ƃ�
SP<AbstractGunPowder> PowderBuilder::Build() {
	{
		auto p = std::dynamic_pointer_cast<IOneArgFunction>(function);
		if (p != nullptr) return OneArgPowder::Build(p);
	}
	{
		auto p = std::dynamic_pointer_cast<LeafX>(function);
		if (p != nullptr) return SP<AbstractGunPowder>(new LeafXPowder(p));
	}
	assert(false);
}


}
}