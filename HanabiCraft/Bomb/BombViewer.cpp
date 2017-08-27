#include "BombViewer.h"

namespace HanabiCraft {
namespace Bomb {


BombViewer::BombViewer(const RectF & v, SP<AbstractGunPowder> powder)
	: v(v), baseCircle(v.x + v.w/2, v.y + v.h/2, Min(v.w, v.h)/2*0.8) {
	powders.push_back(powder);
}

void BombViewer::Update() {
	auto containedPowderIndex = [&](const Vec2 &pos) {
		for (int i = 0; i < powders.back()->ChildCount(); i++) {
			if (powders.back()->ChildCircle(baseCircle, i).contains(pos))
				return i;
		}
		return -1;
	};

	if (Input::MouseL.released) {
		int index = containedPowderIndex(Mouse::PosF());
		if (index != -1) {
			powders.push_back(powders.back()->GetChild(index));
		}
	}

	v.draw(Palette::White);
	powders.back()->Update(baseCircle);
}




}
}