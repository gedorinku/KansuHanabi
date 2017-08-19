#include "GunPowder.h"
namespace HanabiCraft {
namespace BombViewer {


GunPowder::GunPowder(const Vec2 &origin, double r, SP<Function::Parent<GunPowder>> function)
	: origin(origin)
	, r(r)
	, function(function) {}

double GunPowder::Eval(double x) {
	return function->Eval(x);
}


}
}