#pragma once
#include "Function.h"

namespace hanabi {
	class Multiplication :
		public Function
	{
	public:
		Multiplication() = default;
		Multiplication(const Multiplication& obj);
		~Multiplication() override = default;

		double evaluate(double x) const override;
	};
}

