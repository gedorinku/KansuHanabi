#pragma once
#include "Function.h"

namespace hanabi {
	class Multiplication :
		public Function
	{
	public:
		Multiplication() = default;
		Multiplication(const Multiplication& obj);
		Multiplication(const Function& function1, const Function& function2);
		~Multiplication() override = default;

		double evaluate(double x) const override;
	};
}

