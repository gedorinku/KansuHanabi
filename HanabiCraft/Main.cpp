#define _USE_MATH_DEFINES
#include <Siv3D.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "Util.h"
#include "Function\Sin.h"
#include "Function\LeafX.h"
using namespace HanabiCraft;

void Main() {
	enum Mode {
		JustRun,
		Function_PoyoTest
	} mode = Mode::Function_PoyoTest;

	if (mode == JustRun) {
	}
	else if (mode == Function_PoyoTest) {
		using namespace Function;
		Console::Open();
		SP<LeafX> p(new LeafX());
		SP<IFunction> q = p;
		printf("%f\n", Function::Sin<>(q).Eval(M_PI*3/2));
	}
}
