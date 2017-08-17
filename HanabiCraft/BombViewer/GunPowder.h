#pragma once
#include <Siv3d.hpp>
#include "..\Basis2D.h"
#include "..\Function\Function.h"
#include <memory>

using namespace HanabiCraft::Function;

namespace HanabiCraft {
namespace BombViewer {


class GunPowder{
private:
	Vec2 origin;
	double r;
	std::unique_ptr<Function::Function> function;
public:
	GunPowder(Vec2 origin, double r, std::unique_ptr<Function::Function> &&function);
	virtual void Update() = 0;
	const Function::Function& GetFunction();
};


}
}