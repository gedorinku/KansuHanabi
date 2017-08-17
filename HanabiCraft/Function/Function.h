#pragma once
#include <vector>
#include "BombViewer\GunPowder.h"

namespace HanabiCraft {
namespace Function {


class Function {
protected:
	std::vector<Function> children;
	virtual double eval(const std::vector<double> &arg) = 0;
public:
	Function(const std::vector<Function> &children);
	double Eval(double x);
	virtual const BombViewer::GunPowder& ToGunPowder() = 0;
	const std::vector<Function>& GetChildren();
};


}
}