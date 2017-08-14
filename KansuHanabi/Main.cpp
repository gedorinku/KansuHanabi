# include <Siv3D.hpp>
# include "Function/Functions.h"

class Hoge
{
public:
	void print()
	{
		LOG(L"aaaa");
	}
};

class Fuga
{
	Hoge hoge;
public:
	Fuga(Hoge&& h) : hoge(h)
	{
		
	}

	void print()
	{
		hoge.print();
	}
};

void Main()
{
	Fuga fuga = Fuga(Hoge());
	fuga.print();
	const Font font(30);
	std::vector<Vector2D<double>> dots;
	constexpr double RATE = 100.0;
	const double INF = pow(10.0, 10.0);
	auto fun = hanabi::Function::composeEmplace<hanabi::Cos>(hanabi::Cos());
	//auto fun = hanabi::Sin();
	//assert(fun.Evaluate(1.0) == std::sin(std::sin(1.0)));
	for (double i = -300.0; i < 300.0; i += 0.01)
	{
		//dots.emplace_back(Vector2D<double>(300 + i, 250 + sin(1 / (i / 220.0)) * 220.0));
		dots.emplace_back(Vector2D<double>(300 + i, 250 + fun.Evaluate(i / RATE) * RATE));
	}

	std::vector<std::pair<Circle, Color>> hanabi;
	for (int i = 0; i < dots.size(); ++i)
	{
		if (Random(400) != 0) continue;
		hanabi.emplace_back(std::make_pair(Circle(dots[i], 2.0), RandomColor()));
	}

	while (System::Update())
	{
		//font(L"ようこそ、Siv3D の世界へ！").draw();

		//Circle(Mouse::Pos(), 50).draw({255, 0, 0, 127});

		for (int i = 0; i < dots.size() - 100; i += 100)
		{
			if (INF < abs(dots[i].y)) continue;
			Line(dots[i], dots[i + 100]).draw();
		}

		for (auto dot : hanabi)
		{
			dot.first.draw(dot.second);
		}
	}
}
