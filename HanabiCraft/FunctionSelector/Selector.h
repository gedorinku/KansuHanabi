#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "Function\AbstractFunction.h"
#include "Hold.h"
#include "functional"

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
	Hold hold;
	std::function<void(SP<Function::AbstractFunction>)> onDrop;
	

public:

	Selector(const RectF &v);

	void SetOnDrop(std::function<void(SP<Function::AbstractFunction>)> onDrop);

	void Update();

	void Draw();
};


}
}