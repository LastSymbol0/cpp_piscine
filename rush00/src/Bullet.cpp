#include "Bullet.hpp"

Bullet::Bullet() :
	AAmunition("bullet", 0, 0, 10, 1, 1, 0, 0)
{
}

Bullet::Bullet(int x, int y) :
	AAmunition("bullet", 0, UP, 10, 1, 1, x, y)
{
}

Bullet::Bullet(int direction) :
	AAmunition("bullet", 0, direction, 10, 1, 1, 0, 0)
{
}

Bullet::Bullet(const Bullet& a) :
	AAmunition(a._type, a._speed, a._direction,
	a._damage, a._width, a._height, a._x, a._y)
{
}

Bullet& Bullet::operator=(Bullet& a)
{
	AAmunition::operator=(a);
	return (*this);
}

Bullet::~Bullet() {
}

IGameEntity*	Bullet::clone() const {
	Bullet* cl = new Bullet(*this);
	return cl;
}
