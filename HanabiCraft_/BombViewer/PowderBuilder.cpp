#include "PowderBuilder.h"
#include "IGunPowder.h"
#include "Function\IOneArgFunction.h"
#include "OneArgPowder.h"
#include "LeafXPowder.h"
#include "Function\LeafX.h"
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace BombViewer {


PowderBuilder::PowderBuilder(SP<AbstractFunction> function) : function(function) {}

//TODO: �C�J�����݌v�ƃR�[�h #�Ƃ�
SP<IGunPowder> PowderBuilder::Build(const Vec2 &pos, double r) {
	{
		auto p = std::dynamic_pointer_cast<IOneArgFunction>(function);
		if (p != nullptr) return OneArgPowder::Build(pos, r, p);
	}
	{
		auto p = std::dynamic_pointer_cast<LeafX>(function);
		if (p != nullptr) return SP<IGunPowder>(new LeafXPowder(p));
	}
	assert(false);
}


}
}