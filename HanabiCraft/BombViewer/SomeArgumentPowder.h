#pragma once
#include <Siv3D.hpp>
#include "GunPowder.h"

namespace HanabiCraft {
namespace BombViewer {


class SomeArgumentPowder : GunPowder {
private:
	
public:
	SomeArgumentPowder(const Vec2 &origin, double r, std::unique_ptr<Function::Function> &&function);
	virtual void Update() override;
};


}
}