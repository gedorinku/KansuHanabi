#include "LeafXPowder.h"

namespace HanabiCraft {
namespace BombViewer {

void LeafXPowder::Update() {}

std::vector<SP<Function::AbstractFunction>> LeafXPowder::GetChildren() {
	return std::vector<SP<AbstractFunction>>();
}

void LeafXPowder::SetChilren(const std::vector<SP<AbstractFunction>>& children) {}

SP<Function::AbstractFunction> LeafXPowder::Clone(const std::vector<SP<AbstractFunction>>& newChildren) {
	return SP<AbstractFunction>();
}

double HanabiCraft::BombViewer::LeafXPowder::WeakEval(double x) {
	return x;
}

Vec2 LeafXPowder::GetPos() { return Vec2(); }

double LeafXPowder::GetR() { return 0.0; }


}
}