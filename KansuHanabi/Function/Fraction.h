#pragma once
#include "Function.h"

namespace hanabi {
	class Fraction : public Function
	{
	public:
		Fraction() = default;
		Fraction(const Function& numerator, const Function& denominator);
		~Fraction() override = default;

		double evaluate(double x) const override;
	};
}
