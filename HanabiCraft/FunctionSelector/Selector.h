#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Function\AbstractFunction.h"

namespace HanabiCraft {
namespace FunctionSelector {


class Selector {
private:

	RectF v;
	double borderSize;
	const int itemCount = 20;
	const double margin = 6;
	std::vector<SP<Function::AbstractFunction>> functions;
	double itemOriginX; //âÊñ è„Ç≈ÇÃà íu
	int selectedIndex;
	Vec2 clickedPos;
	bool isDragged;

public:

	Selector(const RectF &v);

	void Update();
};


}
}