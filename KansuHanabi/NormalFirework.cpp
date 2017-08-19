#include <cmath>
#include <Siv3D.hpp>
#include "NormalFirework.h"


hanabi::NormalFirework::NormalFirework(const NormalFirework& obj)
	: Firework(obj), balls(obj.balls)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, double x, double y, double size)
	: NormalFirework(graph, { x, y }, size)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, const s3d::Vec2& position, double size)
	: Firework(position)
{
	auto time = size * 125.0;
	const auto& vertexes = graph.getVertexes();
	std::random_device rd;
	std::mt19937 mt(rd());
	std::normal_distribution<double> length(0.0, 4.0);
	constexpr auto interval = 0.1;
	double integrated = 0.0;
	std::vector<Vec2> points;
	const auto defaultDeltaX = graph.getDeltaX();
	constexpr double eps = 1.0e-6;
	//”÷•ªŒW”‚ª‘å‚«‚­‚È‚é‚Æ‚±‚ë‚ª‚ ‚é‚ÆA‰Ô‰Î‚ÌŒõ‚ª”ò‚Ñ”ò‚Ñ‚É‚È‚é‚Ì‚ÅA‹Èü‚Ì’·‚³‚ğ‹ß—‚µ‚Ä‚Ù‚°
	for (auto i = 0; i < vertexes.size() - 1; i++)
	{
		const auto delta = vertexes[i + 1] - vertexes[i];
		if (defaultDeltaX + eps < delta.x) continue;
		auto derivative = delta.y / delta.x;
		if (std::isnan(derivative) || std::isinf(derivative))
		{
			derivative = interval / 2.0;
		}
		integrated += std::sqrt(1.0 + derivative * derivative) * delta.x;
		assert(!isnan(integrated) && !isinf(integrated));

		if (interval <= integrated)
		{
			const int count = integrated / interval;
			const auto smallInterval = delta.x / count;
			integrated = 0.0;
			for (auto j = 0; j < count; ++j)
			{
				points.emplace_back(vertexes[i].x + smallInterval * j, vertexes[i].y + derivative * smallInterval * j);
			}
		}
	}
	for (auto i = 0; i < points.size(); i++)
	{
		auto noise = RandomVec2(length(mt));
		balls.emplace_back(NormalFireworkParticle(position, position + points[i] * size + noise, time));
	}
}

hanabi::NormalFirework::~NormalFirework()
{
}

void hanabi::NormalFirework::draw()
{
	Graphics2D::SetBlendState(BlendState::Additive);
	for (auto& ball : balls)
	{
		ball.draw();
	}
	Graphics2D::SetBlendState(BlendState::Default);
}

bool hanabi::NormalFirework::isAlive() const
{
	bool result = false;
	for (auto& ball : balls)
	{
		result |= ball.isAlive();
	}
	return result;
}
