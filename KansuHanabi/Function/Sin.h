#pragma once
#include <memory>
#include "Function.h"

namespace hanabi {
	class Sin : public Function
	{
	public:
		Sin() = default;
		~Sin() override = default;
		double evaluate(double x) const override;
	};
}

