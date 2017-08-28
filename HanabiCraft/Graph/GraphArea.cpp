#include "GraphArea.h"
#include "Bomb\AbstractGunPowder.h"

namespace HanabiCraft {
namespace Graph {


GraphArea::GraphArea(const RectF &v, SP<Bomb::AbstractGunPowder> powder) {
	double length = Min(v.w/2, v.h/3);
	parentGraph = SP<GraphManager>(new GraphManager(v.x, v.y + length, length*2, length*2, powder->GetFunction()));
	if (powder->ChildCount() >= 1)
		childGraph1 = SP<GraphManager>(new GraphManager(v.x, v.y, length, length, powder->GetChild(0)->GetFunction()));
	if (powder->ChildCount() >= 2)
		childGraph2 = SP<GraphManager>(new GraphManager(v.x + length, v.y, length, length, powder->GetChild(1)->GetFunction()));
}

void GraphArea::Update() {
	parentGraph->Update();
	if (childGraph1) childGraph1->Update();
	if (childGraph2) childGraph2->Update();
}

void GraphArea::Draw() {
	parentGraph->Draw();
	if (childGraph1) childGraph1->Draw();
	if (childGraph2) childGraph2->Draw();
}

RectF GraphArea::GetRect() { return v; }


}
}