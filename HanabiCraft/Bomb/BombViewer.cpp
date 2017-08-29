#include "BombViewer.h"
#include "PowderBuilder.h"
#include "PowderWrapper.h"
#include "Function\LeafX.h"
#include "PowderBuilder.h"

namespace HanabiCraft {
namespace Bomb {


BombViewer::BombViewer(const RectF & v, SP<Function::AbstractFunction> function)
	: v(v), controllEnable(true), basePos(v.x + v.w/2, v.y + v.h/2), baseR(Min(v.w, v.h)/2*0.8), bombIndex(0) {
	basePosEasing = EasingController<Vec2>(basePos, basePos, Easing::Linear, 1);
	baseREasing = EasingController<double>(baseR, baseR, Easing::Linear, 1);
	//powders.push_back(PowderBuilder(function).Build());
	bombs.resize(100);
	for (int i = 0; i < bombs.size(); i++) {
		bombs[i] = SP<PowderWrapper>(new PowderWrapper(SP<Function::AbstractFunction>(new LeafX())));
		bombs[i]->SetAllRandomColor(powderTone);
	}
	powders.push_back(bombs[bombIndex]);
	resetDrawMode();
	if (onChange) onChange(*this);
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
			if (powders.back()->ChildCircle(CurrentCircle(), i).contains(pos))
				return i;
		}
		return -1;
	};

	if (controllEnable) {
		if (Input::MouseL.released) {
			int index = containedPowderIndex(Mouse::PosF());
			if (index != -1) {
				Circle start = powders.back()->ChildCircle(CurrentCircle(), index);
				basePosEasing = EasingController<Vec2>(start.center, basePos, Easing::Quint, 400);
				baseREasing = EasingController<double>(start.r, baseR, Easing::Quint, 400);
				powders.push_back(powders.back()->GetChild(index));
				resetDrawMode();
				if (onChange) onChange(*this);
				basePosEasing.start();
				baseREasing.start();
			}
		}
		else if (Input::KeyBackspace.clicked && powders.size() > 1) {
			powders.pop_back();
			resetDrawMode();
			if (onChange) onChange(*this);
		}
		else if (Input::KeyRight.clicked && bombIndex < bombs.size() - 1) {
			powders = {bombs[++bombIndex]};
			resetDrawMode();
			if (onChange) onChange(*this);
		}
		else if (Input::KeyLeft.clicked && 0 < bombIndex) {
			powders = {bombs[--bombIndex]};
			resetDrawMode();
			if (onChange) onChange(*this);
		}
	}
	controllEnable = true;
}

void BombViewer::Draw() {
	auto c = CurrentCircle();
	powders.back()->Draw(c);
	static Font font(25);
	font(bombIndex).draw(v.x, v.y + v.h - 50, Palette::Orange);
}

void BombViewer::Drop(SP<Function::AbstractFunction> function) {
	controllEnable = false;
	bool valid = [&]() {
		for (int i = 0; i < powders.back()->ChildCount(); i++) {
			Circle c = powders.back()->ChildCircle(CurrentCircle(), i);
			c.r += 20;
			if (c.mouseOver) return true;
		}
		return false;
	} ();
	if (!valid) return;
	int droppedIndex = -1;
	double minDist = 1e50;
	for (int i = 0; i < powders.back()->ChildCount(); i++) {
		double d = powders.back()->ChildCircle(CurrentCircle(), i).center.distanceFrom(Mouse::Pos());
		if (d < minDist) {
			minDist = d; droppedIndex = i;
		}
	}
	auto newChild = PowderBuilder(function).Build();
	newChild->SetAllRandomColor(powderTone);
	powders.back()->SetChild(droppedIndex, newChild);
	resetDrawMode();
	if (onChange) onChange(*this);
}

void BombViewer::SetOnChange(std::function<void(const BombViewer&)> onMove) {
	this->onChange = onMove;
}

SP<AbstractGunPowder> BombViewer::SelectedPowder() const {
	return powders.back();
}

Circle BombViewer::CurrentCircle() {
	return Circle(basePosEasing.easeOut(), baseREasing.easeOut());
}

void BombViewer::SetBomb(int index, SP<Function::AbstractFunction> bomb) {
	if (index < 0 || bombs.size() <= index) return;
	bombs[index] = SP<PowderWrapper>(new PowderWrapper(bomb));
}


	std::vector<SP<Function::AbstractFunction>> BombViewer::GetBombs()
	{
		std::vector<SP<AbstractFunction>> ret;
		for (int i = 0; i < bombs.size(); i++)
		{
			ret.push_back(bombs[i]->GetFunction()->DeepClone());
		}
		return ret;
	}
}
}