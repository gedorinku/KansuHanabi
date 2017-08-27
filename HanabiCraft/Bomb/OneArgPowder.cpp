#include "OneArgPowder.h"
#include "PowderBuilder.h"
using namespace HanabiCraft::Function;

namespace HanabiCraft {
namespace Bomb {


OneArgPowder::OneArgPowder(SP<Function::IOneArgFunction> function,
						   SP<AbstractGunPowder> child,
						   const Color &color)
	: AbstractGunPowder(color)
	, function(function)
	, child(child) {}

SP<OneArgPowder> OneArgPowder::Build(SP<IOneArgFunction> function) {
	auto child = PowderBuilder(function->GetChild()).Build();
	return SP<OneArgPowder>(new OneArgPowder(function, child));
}

void OneArgPowder::update(const Circle &base) {}

double OneArgPowder::WeakEval(double x) {
	return function->WeakEval(x);
}

SP<AbstractFunction> OneArgPowder::GetChild() {
	return function->GetChild();
}

void OneArgPowder::SetChild(SP<AbstractFunction> child) {
	function->SetChild(child);
	this->child = PowderBuilder(child).Build();
}

SP<Function::AbstractFunction> OneArgPowder::Clone(SP<Function::AbstractFunction> newChild) {
	return function->Clone(newChild);
}

SP<Function::AbstractFunction> OneArgPowder::GetFunction() {
	return function;
}

int OneArgPowder::ChildCount() {
	return 1;
}

SP<AbstractGunPowder> OneArgPowder::GetChild(int index) {
	if (index != 0) return nullptr;
	return child;
}

void OneArgPowder::SetChild(int index, SP<AbstractGunPowder> child) {
	this->child = child;
	function->SetChild(child->GetFunction());
}

Circle OneArgPowder::ChildCircle(const Circle &base, int index) {
	return Circle(base.center, base.r*0.9);
}

void OneArgPowder::drawAll(const Circle & base) {
	base.drawFrame(1, 1, Palette::Black);
	child->Update(ChildCircle(base, 0));
}


}
}