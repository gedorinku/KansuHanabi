#include "LeafXPowder.h"

namespace HanabiCraft {
namespace BombViewer {

void LeafXPowder::Update() {}

std::vector<SP<Function::IFunction>> LeafXPowder::GetChildren() {
	return std::vector<SP<IFunction>>();
}

void LeafXPowder::SetChilren(const std::vector<SP<IFunction>>& children) {}

SP<Function::IFunction> LeafXPowder::Clone(const std::vector<SP<IFunction>>& newChildren) {
	return SP<IFunction>();
}

double HanabiCraft::BombViewer::LeafXPowder::Eval(double x) {
	return x;
}

Vec2 LeafXPowder::GetPos() { return Vec2(); }

double LeafXPowder::GetR() { return 0.0; }


}
}