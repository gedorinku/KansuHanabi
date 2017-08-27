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

public:

	BombViewer(const RectF &v, SP<AbstractGunPowder> powder);

	void Update();
};


}
}