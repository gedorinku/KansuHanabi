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
		None
	};

private:

	DrawMode mode = All;
	Color color;

protected:

	AbstractGunPowder(const Color &color) : color(color) {}

	//DrawModeÇ…ä÷ÇÌÇÁÇ∏Ç∑ÇÈèàóù
	virtual void update(const Circle &base) = 0;

	virtual void drawAll(const Circle &base) = 0;

public:

	void Update(const Circle &base) {
		update(base);
		switch (mode) {
		case HanabiCraft::Bomb::AbstractGunPowder::All:
			drawAll(base);
			break;
		case HanabiCraft::Bomb::AbstractGunPowder::None:
			break;
		default:
			break;
		}
	}

	virtual int ChildCount() = 0;

	virtual SP<AbstractGunPowder> GetChild(int index) = 0;

	virtual void SetChild(int index, SP<AbstractGunPowder> child) = 0;

	virtual SP<Function::AbstractFunction> GetFunction() = 0;

	virtual Circle ChildCircle(const Circle &base, int index) = 0;

	Color GetColor() { return color; }

	Color CreateChildColor(int index) {
		HSV hsv(color);
		return HSV(Random(), hsv.s, hsv.v);
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
};


}
}