#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Function\AbstractFunction.h"

namespace HanabiCraft {
namespace Bomb {


class AbstractGunPowder {
public:

	enum DrawMode {
		All,
		None,
		Frame
	};

private:

	DrawMode mode = All;
	Color color;

protected:

	virtual void update(const Circle &base) = 0;

	virtual void drawAll(const Circle &base) = 0;

	virtual void drawFrame(const Circle &base) {
		base.drawFrame(4, 2, Palette::White);
		base.drawFrame(2, 0, Palette::Black);
	}

public:

	virtual int ChildCount() = 0;

	virtual SP<AbstractGunPowder> GetChild(int index) = 0;

	virtual void SetChild(int index, SP<AbstractGunPowder> child) = 0;

	virtual SP<Function::AbstractFunction> GetFunction() = 0;

	virtual Circle ChildCircle(const Circle &base, int index) = 0;

	void SetColor(const Color &color) { this->color = color; }

	Color GetColor() { return color; }

	//このノードと含むノード全てを、ランダムな色相に
	void SetAllRandomColor(const HSV &tone) {
		SetColor(HSV(Random(360), tone.s, tone.v));
		for (int i = 0; i < ChildCount(); i++) {
			GetChild(i)->SetAllRandomColor(tone);
		}
	}

	DrawMode GetDrawMode() { return mode; }

	void SetDrawMode(DrawMode mode) {
		this->mode = mode;
	}

	void SetChildrenDrawMode(DrawMode mode) {
		for (int i = 0; i < ChildCount(); i++) {
			GetChild(i)->SetDrawMode(mode);
			GetChild(i)->SetChildrenDrawMode(mode);
		}
	}

	void Update(const Circle &base) {
		update(base);
		for (int i = 0; i < ChildCount(); i++) {
			GetChild(i)->Update(ChildCircle(base, 0));
		}
	}

	void Draw(const Circle &base) {
		switch (mode) {
		case All:
			drawAll(base);
			break;
		case None:
			break;
		case Frame:
			drawFrame(base);
			break;
		default:
			break;
		}
		for (int i = 0; i < ChildCount(); i++) {
			GetChild(i)->Draw(ChildCircle(base, 0));
		}
	}
};


}
}