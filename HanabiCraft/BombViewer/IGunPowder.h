#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Function\IFunction.h"

namespace HanabiCraft {
namespace BombViewer {


class IGunPowder : Function::IFunction{
public:

	virtual void Update() = 0;

	virtual double Eval(double x) override = 0;
};


}
}