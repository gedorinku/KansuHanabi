#pragma once
#include <Siv3D.hpp>
#include "Scale2D.h"
#include "Coordinates2D.h"

namespace HanabiCraft {


class Basis2D {
private:
	Coordinates2D origin, size;
public:
	Basis2D(double x, double y, double w, double h);
	Basis2D(const Coordinates2D &pos, const Coordinates2D &size);
	double Origin();
	double Size();
	double X();
	double Y();
	double W();
	double H();
	Scale2D GetScale(double scaleX, double scaleY);

};
typedef Basis2D Area2D;


}