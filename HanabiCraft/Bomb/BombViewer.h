#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include <vector>
#include "AbstractGunPowder.h"
#include "PowderWrapper.h"

namespace HanabiCraft {
namespace Bomb {


class BombViewer {
private:

	RectF v;
	Vec2 basePos;
	double baseR;
	EasingController<Vec2> basePosEasing;
	EasingController<double> baseREasing;
	std::vector<SP<AbstractGunPowder>> powders;
	const HSV powderTone = HSV(0, 0.8, 0.8);
	bool controllEnable;
	std::vector<SP<PowderWrapper>> bombs;
	int bombIndex;
	std::function<void(const BombViewer&)> onChange;

	void resetDrawMode();

public:

	BombViewer(const RectF &v, SP<Function::AbstractFunction> function);

	void Update();

	void Draw();

	void Drop(SP<Function::AbstractFunction> function);

	void SetOnChange(std::function<void(const BombViewer&)> onMove);

	SP<AbstractGunPowder> SelectedPowder() const;

	Circle CurrentCircle();

	void SetBomb(int index, SP<Function::AbstractFunction> bomb);

	std::vector<SP<Function::AbstractFunction>> GetBombs();
};


}
}