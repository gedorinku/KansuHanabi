#pragma once
#include "Function.h"

namespace hanabi {
	class Fraction : public Function
	{
	public:
		Fraction() = default;
		~Fraction() override = default;

		double Evaluate(double x) override;
	};
}
