#pragma once
#include <Siv3d.hpp>
#include "..\Basis2D.h"
#include "..\Function\Function.h"

using namespace HanabiCraft::Function;

namespace HanabiCraft {
namespace HanabiViewer {


class GunPowder {
private:
	Vec2 origin;
	double r;
public:
	Function::Function GetFunction();
	
};


}
}