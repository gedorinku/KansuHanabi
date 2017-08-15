#pragma once
#include "Function.h"

namespace hanabi {
	class Cos : public Function
	{
	public:
		Cos() = default;
		~Cos() override = default;
		double evaluate(double x) const override;
	};
}

