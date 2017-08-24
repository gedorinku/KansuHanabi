#pragma once
#include <Siv3D.hpp>
#include "Util.h"

namespace HanabiCraft {
namespace BombViewer {


class IGunPowder {
public:

	virtual void Update() = 0;

	virtual Vec2 GetPos() = 0;

	virtual double GetR() = 0;
};


}
}