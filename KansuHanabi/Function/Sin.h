#pragma once
#include <memory>
#include "Function.h"

namespace hanabi {
	class Sin : public Function
	{
	public:
		Sin();
		Sin(const Sin& obj);
		~Sin() override;
		double Evaluate(double x) override;
	};
}

