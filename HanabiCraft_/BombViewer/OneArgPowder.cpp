#include "OneArgPowder.h"
#include "PowderBuilder.h"
using namespace HanabiCraft::Function;

namespace HanabiCraft {
namespace BombViewer {


OneArgPowder::OneArgPowder(const Vec2 &pos,
						   double r,
						   SP<Function::IOneArgFunction> function,
						   SP<IGunPowder> child)
	: pos(pos)
	, r(r)
	, function(function)
	, child(child) {}

SP<OneArgPowder> OneArgPowder::Build(const Vec2 &pos, double r, SP<IOneArgFunction> function) {
	auto child = PowderBuilder(function->GetChild()).Build(pos, r*0.9);
	return SP<OneArgPowder>(new OneArgPowder(pos, r, function, child));
}

void OneArgPowder::Update() {
	Circle(pos, r).draw();
}

double OneArgPowder::WeakEval(double x) {
	return function->WeakEval(x);
}

SP<AbstractFunction> OneArgPowder::GetChild() {
	return function->GetChild();
}

void OneArgPowder::SetChild(SP<AbstractFunction> child) {
	function->SetChild(child);
	this->child = PowderBuilder(child).Build(this->child->GetPos(), this->child->GetR());
}

SP<Function::AbstractFunction> OneArgPowder::Clone(SP<Function::AbstractFunction> newChild) {
	return SP<Function::AbstractFunction>();
}

Vec2 OneArgPowder::GetPos() { return pos; }

double OneArgPowder::GetR() { return r; }


}
}