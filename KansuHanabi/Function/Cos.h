#pragma once
#include "Function.h"

namespace hanabi {
	class Cos : public Function
	{
	public:
		Cos() = default;
		~Cos() override = default;
		double Evaluate(double x) override;
	};
}

