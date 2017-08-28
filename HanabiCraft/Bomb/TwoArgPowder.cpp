#include "TwoArgPowder.h"
#include "PowderBuilder.h"

namespace HanabiCraft {
namespace Bomb {


TwoArgPowder::TwoArgPowder(SP<Function::AbstractFunction> function,
						   SP<AbstractGunPowder> child1,
						   SP<AbstractGunPowder> child2)
	: function(function), child1(child1), child2(child2) {
	rad = Random(2*Pi);
}

SP<TwoArgPowder> TwoArgPowder::Build(SP<Function::TwoArgFunction> function) {
	auto child1 = PowderBuilder(function->GetChild1()).Build();
	auto child2 = PowderBuilder(function->GetChild2()).Build();
	return SP<TwoArgPowder>(new TwoArgPowder(function, child1, child2));
}

void HanabiCraft::Bomb::TwoArgPowder::update(const Circle & base) {}

void HanabiCraft::Bomb::TwoArgPowder::drawAll(const Circle & base) {}

int HanabiCraft::Bomb::TwoArgPowder::ChildCount() {
	return 2;
}

SP<AbstractGunPowder> HanabiCraft::Bomb::TwoArgPowder::GetChild(int index) {
	if (index == 0) return child1;
	if (index == 1) return child2;
	return nullptr;
}

void HanabiCraft::Bomb::TwoArgPowder::SetChild(int index, SP<AbstractGunPowder> child) {
	if (index == 0) child1 = child;
	if (index == 1) child2 = child;
}

SP<Function::AbstractFunction> HanabiCraft::Bomb::TwoArgPowder::GetFunction() {
	return function;
}

Circle HanabiCraft::Bomb::TwoArgPowder::ChildCircle(const Circle & base, int index) {
	if (index == 0)
		return Circle(base.x + base.r/2*Cos(rad), base.y + base.r/2*Sin(rad), base.r/2*0.85);
	if (index == 1)
		return Circle(base.x + base.r/2*Cos(rad + Pi), base.y + base.r/2*Sin(rad + Pi), base.r/2*0.85);
}


}
}