#include "OneArgumentPowder.h"

namespace HanabiCraft {
namespace BombViewer {



OneArgumentPowder::OneArgumentPowder(const Vec2 & origin,
									 double r,
									 std::unique_ptr<Function::Function>&& function)
	: GunPowder(origin, r, std::move(function)) {}
void OneArgumentPowder::Update() {
	Circle()
}


}
}