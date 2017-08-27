#include "BombViewer.h"
#include "PowderBuilder.h"
#include "PowderWrapper.h"
#include "Function\LeafX.h"

namespace HanabiCraft {
namespace Bomb {


BombViewer::BombViewer(const RectF & v, SP<Function::AbstractFunction> function)
	: v(v), baseCircle(v.x + v.w/2, v.y + v.h/2, Min(v.w, v.h)/2*0.8), isDropped(false) {
	//powders.push_back(PowderBuilder(function).Build());
	powders.push_back(SP<AbstractGunPowder>(new PowderWrapper(SP<Function::AbstractFunction>(new LeafX()))));
	powders.back()->SetAllRandomColor(powderTone);
}

void BombViewer::resetDrawMode() {
	powders[0]->SetChildrenDrawMode(AbstractGunPowder::DrawMode::None);
	powders.back()->SetDrawMode(AbstractGunPowder::DrawMode::All);
	for (int i = 0; i < powders.back()->ChildCount(); i++) {
		auto child = powders.back()->GetChild(i);
		child->SetDrawMode(AbstractGunPowder::DrawMode::All);
		child->SetChildrenDrawMode(AbstractGunPowder::DrawMode::Frame);
	}
}

void BombViewer::Update() {
	auto containedPowderIndex = [&](const Vec2 &pos) {
		for (int i = 0; i < powders.back()->ChildCount(); i++) {
			if (powders.back()->GetChild(i)->ChildCount() == 0) continue;
			if (powders.back()->ChildCircle(baseCircle, i).contains(pos))
				return i;
		}
		return -1;
	};

	if (Input::MouseL.released && !isDropped) {
		int index = containedPowderIndex(Mouse::PosF());
		if (index != -1) {
			powders.push_back(powders.back()->GetChild(index));
			resetDrawMode();
		}
	}

	if (Input::KeyBackspace.clicked && powders.size() > 1) {
		powders.pop_back();
		resetDrawMode();
	}
	isDropped = false;
}

void BombViewer::Draw() {
	v.draw(Palette::White);
	powders.back()->Draw(baseCircle);
}

void BombViewer::Drop(SP<Function::AbstractFunction> function) {
	isDropped = true;
	bool valid = [&]() {
		for (int i = 0; i < powders.back()->ChildCount(); i++) {
			Circle c = powders.back()->ChildCircle(baseCircle, i);
			c.r += 20;
			if (c.mouseOver) return true;
		}
		return false;
	} ();
	if (!valid) return;
	int droppedIndex = -1;
	double minDist = 1e50;
	for (int i = 0; i < powders.back()->ChildCount(); i++) {
		double d = powders.back()->ChildCircle(baseCircle, i).center.distanceFrom(Mouse::Pos());
		if (d < minDist) {
			minDist = d; droppedIndex = i;
		}
	}
	auto newChild = PowderBuilder(function).Build();
	newChild->SetAllRandomColor(powderTone);
	powders.back()->SetChild(droppedIndex, newChild);
}


}
}