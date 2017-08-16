# include <Siv3D.hpp>
# include "Function/Functions.h"
# include "NormalFirework.h"
#include "Graph/XYGraph.h"

void Main()
{
	const Font font(30);
	auto firework = hanabi::NormalFirework(hanabi::XYGraph(hanabi::Sin(), -5.0, 5.0), 300.0, 300.0, 50);
	long count = 0;
	while (System::Update())
	{
		if (100 < count) {
			firework.draw();
		}
		count++;
		font(Profiler::FPS(), L"fps").draw();
	}
}
