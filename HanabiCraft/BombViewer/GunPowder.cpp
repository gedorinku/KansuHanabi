#include "GunPowder.h"

namespace HanabiCraft {
namespace BombViewer {


GunPowder::GunPowder(Vec2 origin, double r, std::unique_ptr<Function::Function> &&function)
	: origin(origin)
	, r(r)
	, function(std::move(function)) {}
const Function::Function& GunPowder::GetFunction() {
	return *function;
}


}
}