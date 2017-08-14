#pragma once
#include "Function.h"

namespace hanabi {
	class Cos : public Function
	{
	public:
		Cos();
		~Cos() override;
		double Evaluate(double x) override;
	};
}

