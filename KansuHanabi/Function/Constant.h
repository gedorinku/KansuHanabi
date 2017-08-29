#pragma once
#include "Function.h"

namespace hanabi {
	class Constant : public Function
	{
	public:
		explicit Constant(double value);
		Constant(const Constant& obj);
		~Constant() override = default;

		double evaluate(double x) const override;

	private:
		double value;
	};
}

