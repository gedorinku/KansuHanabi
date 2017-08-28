#pragma once
#include "Function.h"

namespace hanabi {
	class Cos : public Function
	{
	public:
		Cos() = default;
		Cos(const Cos& obj);
		~Cos() override = default;
		double evaluate(double x) const override;
	};
}

