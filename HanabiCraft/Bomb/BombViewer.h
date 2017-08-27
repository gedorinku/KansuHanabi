#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include <vector>
#include "AbstractGunPowder.h"

namespace HanabiCraft {
namespace Bomb {


class BombViewer {
private:

	RectF v;
	Circle baseCircle;
	std::vector<SP<AbstractGunPowder>> powders;
	const HSV powderTone = HSV(0, 0.8, 0.8);
	bool isDropped;

	void resetDrawMode();

public:

	BombViewer(const RectF &v, SP<Function::AbstractFunction> function);

	void Update();

	void Draw();

	void Drop(SP<Function::AbstractFunction> function);
};


}
}