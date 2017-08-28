#pragma once
#include <Siv3D.hpp>
#include "Util.h"
#include "AbstractGunPowder.h"
#include "OneArgPowder.h"

namespace HanabiCraft {
namespace Bomb {


class PowderWrapper : public OneArgPowder {
private:

	String name;

public:
	
	PowderWrapper(SP<Function::AbstractFunction> content);

	virtual Circle ChildCircle(const Circle &base, int index) override;

	void SetName(const String &name);

	String GetName();
};


}
}