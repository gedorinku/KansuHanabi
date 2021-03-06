#include "LeafXPowder.h"

namespace HanabiCraft {
namespace Bomb {


LeafXPowder::LeafXPowder(SP<Function::LeafX> function) : function(function) {}

void LeafXPowder::update(const Circle &base) {}

std::vector<SP<Function::AbstractFunction>> LeafXPowder::GetChildren() {
	return std::vector<SP<AbstractFunction>>();
}

void LeafXPowder::SetChilren(const std::vector<SP<AbstractFunction>>& children) {}

SP<Function::AbstractFunction> LeafXPowder::Clone(const std::vector<SP<AbstractFunction>>& newChildren) {
	return SP<AbstractFunction>();
}

double LeafXPowder::WeakEval(double x) {
	return x;
}

SP<Function::AbstractFunction> LeafXPowder::GetFunction() {
	return function;
}

int LeafXPowder::ChildCount() {
	return 0;
}

SP<AbstractGunPowder> LeafXPowder::GetChild(int index) {
	return nullptr;
}

void LeafXPowder::SetChild(int index, SP<AbstractGunPowder> child) {}

Circle LeafXPowder::ChildCircle(const Circle &base, int index) {
	throw "子ノードを持ちません";
}

void LeafXPowder::drawAll(const Circle & base) {
	base.draw(GetColor());
	base.drawFrame(4, 2, Palette::White);
	base.drawFrame(2, 0, Palette::Black);
}


}
}