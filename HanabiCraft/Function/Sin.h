#pragma once
#include "Util.h"
#include "OneArgumentFunction.h"
#include <cmath>

namespace HanabiCraft {
namespace Function {


//Derived: IFunction‚ðŽÀ‘•‚µ‚Ä‚¢‚é
template<class Derived = IFunction>
class Sin sealed : public OneArgumentFunction<Derived> {
private:

	double eval(const std::vector<double> &args) {
		return std::sin(args[0]);
	}

public:

	Sin(const SP<Derived> &child) : OneArgumentFunction<Derived>(child) {}

	template<class T> Sin(const Sin<T> &source, SP<Derived> &newChild)
		: OneArgumentFunction<Derived>(source, newChild) {}
};


}
}