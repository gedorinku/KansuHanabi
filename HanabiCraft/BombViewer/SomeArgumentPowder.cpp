#include "SomeArgumentPowder.h"

namespace HanabiCraft {
namespace BombViewer {


SomeArgumentPowder::SomeArgumentPowder(const Vec2 & origin,
									   double r,
									   std::unique_ptr<Function::Function>&& function)
	: GunPowder(origin, r, std::move(function)) {}
void SomeArgumentPowder::Update() {

}


}
}