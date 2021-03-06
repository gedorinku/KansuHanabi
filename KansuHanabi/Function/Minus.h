#pragma once
#include "Function.h"

namespace hanabi {
	class Minus :
		public Function
	{
	public:
		Minus() = default;
		Minus(const Minus& obj);
		~Minus() override = default;

		double evaluate(double x) const override;
	};
}

