#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Function\AbstractFunction.h"
#include "Hold.h"

namespace HanabiCraft {
namespace FunctionSelector {


class Selector {
private:

	RectF v;
	double borderSize;
	const int itemCount = 20;
	const double margin = 6;
	std::vector<SP<Function::AbstractFunction>> functions;
	double itemOriginX; //画面上での位置
	int selectedIndex;
	Hold hold;

public:

	Selector(const RectF &v);

	void Update();
};


}
}