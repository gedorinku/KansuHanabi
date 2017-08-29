#include "Firework.h"


hanabi::Firework::Firework(const Firework& obj)
	: position(obj.position)
{
}

hanabi::Firework::Firework(double x, double y)
	: position({x, y})
{
}

hanabi::Firework::Firework(const s3d::Vec2& position)
	: position(position)
{
}

hanabi::Firework::~Firework()
{
}

