#include "PowderWrapper.h"
#include "Function\X.h"
#include "OneArgPowder.h"
#include "Function\LeafX.h"
#include "PowderBuilder.h"

namespace HanabiCraft {
namespace Bomb {


PowderWrapper::PowderWrapper(SP<Function::AbstractFunction> content)
	: OneArgPowder(*OneArgPowder::Build(SP<Function::IOneArgFunction>(new Function::X(content)))) {
	SetDrawMode(AbstractGunPowder::DrawMode::None);
}

Circle PowderWrapper::ChildCircle(const Circle & base, int index) {
	return base;
}

void PowderWrapper::SetName(const String & name) { this->name = name; }

String PowderWrapper::GetName() {
	return name;
}


}
}