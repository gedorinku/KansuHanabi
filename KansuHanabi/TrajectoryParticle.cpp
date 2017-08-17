#include <Siv3D.hpp>
#include "TrajectoryParticle.h"



hanabi::TrajectoryParticle::TrajectoryParticle(double x, double y, long lifeTime)
	: TrajectoryParticle({x, y}, lifeTime)
{
}

hanabi::TrajectoryParticle::TrajectoryParticle(s3d::Vec2 position, long lifeTime)
	: position(position), lifeTime(lifeTime)
{
	createdAtMillis = Time::GetMillisec64();
}

hanabi::TrajectoryParticle::TrajectoryParticle(const TrajectoryParticle& obj)
	: position(obj.position), createdAtMillis(obj.createdAtMillis), lifeTime(obj.lifeTime)
{
}

hanabi::TrajectoryParticle::~TrajectoryParticle()
{
}

bool hanabi::TrajectoryParticle::draw(const s3d::Color color)
{
	if (lifeTime < Time::GetMillisec64() - createdAtMillis)
	{
		return false;
	}

	Circle(position, 0.25).draw(color);
	return true;
}

bool hanabi::TrajectoryParticle::isAlive()
{
	return Time::GetMillisec64() - createdAtMillis <= lifeTime;
}
