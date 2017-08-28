#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Bomb\BombViewer.h"
#include "FunctionSelector\Selector.h"
#include "Graph\GraphArea.h"

namespace HanabiCraft {


class CraftUI {
private:

	RectF v;
	RectF r3;
	SP<FunctionSelector::Selector> selector;
	SP<Bomb::BombViewer> bombViewer;
	SP<Graph::GraphArea> graphArea;

public:

	CraftUI(const RectF &v);

	void Update();
};


}