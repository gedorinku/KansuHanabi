#pragma once
#include "Util.h"
#include "Parent.h"

namespace HanabiCraft {
namespace Function {


template<class Derived>
class OneArgumentFunction : public Parent<Derived> {
protected:

	OneArgumentFunction(const SP<Derived> &child) : Parent<Derived>({child}) {}

	OneArgumentFunction(const OneArgumentFunction &source, const SP<Derived> &newChild)
		: Parent<Derived>(source, {newChild}) {}
};


}
}