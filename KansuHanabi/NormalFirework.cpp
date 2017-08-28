#include <cmath>
#include <Siv3D.hpp>
#include "NormalFirework.h"


hanabi::NormalFirework::NormalFirework(const NormalFirework& obj)
	: Firework(obj), balls(obj.balls), buffer(obj.buffer), delta(obj.delta), blurredTexture(obj.blurredTexture), scale(obj.scale), lifeTime(obj.lifeTime)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, double x, double y, double size)
	: NormalFirework(graph, { x, y }, size)
{
}

hanabi::NormalFirework::NormalFirework(const Graph& graph, const s3d::Vec2& position, double size)
	: Firework(position),
		buffer(std::make_shared<Image>(size * 10, size * 10))
{
	delta = -Vec2{ buffer->size.x, buffer->size.y } / 2.0;
	lifeTime = size * 125.0;
	scale = EasingController<double>(0.0, 1.0, Easing::Expo, lifeTime);
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

	std::shared_ptr<Image> blurBuffer = std::make_shared<Image>(buffer->size);
	blurBuffer->fill({ 0, 0, 0, 0 });
	const Point center(size * 5, size * 5);
	for (auto i = 0; i < points.size(); i++)
	{
		const auto noise = RandomVec2(length(mt));
		const auto &parentPosition = position + delta;
		const auto &start = center;
		const auto &end = center + points[i] * size + noise;

		NormalFireworkParticle(blurBuffer, parentPosition, end, start, lifeTime).draw();

		balls.emplace_back(NormalFireworkParticle(buffer, parentPosition, start, end, lifeTime));
	}

	blurBuffer->gaussianBlur(15, 15);
	blurBuffer->forEach([&](Color &pixcel) -> void {
		pixcel.a *= 5;
	});
	blurredTexture.fill(*blurBuffer);
}

hanabi::NormalFirework::~NormalFirework()
{
}

void hanabi::NormalFirework::draw()
{
	if (!scale.isActive())
	{
		scale.start();
		startAtMillis = Time::GetMillisec64();
	}
	buffer->fill({ 0, 0, 0, 0 });
	for (auto& ball : balls)
	{
		ball.draw();
	}
	Graphics2D::SetBlendState(BlendState::Additive);
	texture.fill(*buffer);
	texture.draw(position + delta);
	//texture.fill(buffer->gaussianBlurred(16, 16));
	//texture.draw(position + delta);
	//for (int i = 0; i < 5; ++i) {
	const auto elapsedTime = Time::GetMillisec64() - startAtMillis;
	if (elapsedTime < lifeTime / 3.0) {
		blurredTexture.scale(scale.easeOut()).draw(position + delta * scale.easeOut() - NormalFireworkParticle::gravity * elapsedTime * elapsedTime);
	} else 
	{
		std::cout << std::endl;
	}
	//
	//}
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
