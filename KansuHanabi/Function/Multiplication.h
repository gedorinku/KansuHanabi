#pragma once
#include "Function.h"

namespace hanabi {
	class Multiplication :
		public Function
	{
	public:
		Multiplication() = default;
		Multiplication(const Multiplication& obj);
		template <class Type1, class Type2>
		Multiplication(const Type1& function1, const Type2& function2);
		~Multiplication() override = default;

		double evaluate(double x) const override;
	};

	template <class Type1, class Type2>
	inline Multiplication::Multiplication(const Type1 & function1, const Type2 & function2)
	{
		innerFunctions.emplace_back(std::make_shared<Type1>(function1));
		innerFunctions.emplace_back(std::make_shared<Type2>(function2));
	}
}

