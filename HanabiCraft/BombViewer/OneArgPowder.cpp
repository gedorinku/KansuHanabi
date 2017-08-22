#include "OneArgPowder.h"
using namespace HanabiCraft::Function;

namespace HanabiCraft {
namespace BombViewer {


SP<OneArgPowder> OneArgPowder::Build(SP<IOneArgFunction> function) {
	return SP<OneArgPowder>();
}

std::vector<SP<IFunction>> OneArgPowder::GetChildren() {
	Util::CastVector(children);
}

void OneArgPowder::SetChilren(const std::vector<SP<IFunction>>& children) {}

void OneArgPowder::Update() {}

double OneArgPowder::Eval(double x) {
	return 0.0;
}

}
}