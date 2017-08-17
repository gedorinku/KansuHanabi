#pragma once
#include "Function.h"

namespace hanabi {
	class Fraction : public Function
	{
	public:
		Fraction() = default;
		template <class Type1, class Type2>
		Fraction(const Type1& numerator, const Type2& denominator);
		~Fraction() override = default;

		double evaluate(double x) const override;
	};

	template <class Type1, class Type2>
	inline Fraction::Fraction(const Type1 & numerator, const Type2 & denominator)
	{
		innerFunctions.emplace_back(std::make_shared<Type1>(numerator));
		innerFunctions.emplace_back(std::make_shared<Type2>(denominator));
	}
}
