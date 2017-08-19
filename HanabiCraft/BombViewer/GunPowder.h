#pragma once
#include <Siv3D.hpp>
#include "Function\Parent.h"
#include "Function\IFunction.h"

namespace HanabiCraft {
namespace BombViewer {


class GunPowder : Function::IFunction{
private:

	Vec2 origin;
	double r;
	SP<Function::Parent<GunPowder>> function;

public:

	GunPowder(const Vec2 &origin, double r, SP<Function::Parent<GunPowder>> function);

	virtual void Update() = 0;

	virtual double Eval(double x) override;
};


}
}