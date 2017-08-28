#pragma once
#include <Siv3D.hpp>
#include "GraphManager.h"
#include "Graph.h"
#include "Bomb\AbstractGunPowder.h"

namespace HanabiCraft {
namespace Graph {


class GraphArea {
private:
	
	RectF v;
	SP<GraphManager> childGraph1, childGraph2;
	SP<Graph> parentGraph;

public:

	GraphArea(const RectF &v, SP<Bomb::AbstractGunPowder> powder);

	void Update();

	void Draw();

	RectF GetRect();
};


}
}