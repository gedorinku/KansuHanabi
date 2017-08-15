#pragma once
#include "Function.h"

namespace hanabi {
	class Summation :
		public Function
	{
	public:
		Summation() = default;
		Summation(const Summation& obj);
		~Summation() override = default;

		double Evaluate(double x) override;
	};
}

