#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Bomb\BombViewer.h"
#include "FunctionSelector\Selector.h"

namespace HanabiCraft {


class CraftUI {
private:

	RectF v;
	SP<FunctionSelector::Selector> selector;
	SP<Bomb::BombViewer> bombViewer;

public:

	CraftUI(const RectF &v);

	void Update();
};


}