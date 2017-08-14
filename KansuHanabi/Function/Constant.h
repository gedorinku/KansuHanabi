#pragma once
#include "Function.h"

namespace hanabi {
	class Constant : public Function
	{
	public:
		explicit Constant(double value);
		Constant(const Constant& obj);
		~Constant() override = default;

		double Evaluate(double x) override;

	private:
		double value;
	};
}

