#include "Enemy.hpp"

Enemy::Enemy() : ACharacter("enemy", "enemy", 1, 20, 3, 2, 0, MAP_HEIGHT - 1, new Gun()),
				_cyclesToMove(0),
				_cyclesToShoot(2)
{
	srand ( time(NULL) );
	_cyclesToShoot = this->getSpeed() * (rand() % 40);
}
Enemy::Enemy(int x, int y) : ACharacter("enemy", "enemy", 1, 20, 3, 2, x, y, new Gun()),
				_cyclesToMove(0),
				_cyclesToShoot(2)
{
	srand ( time(NULL) );
	_cyclesToShoot = this->getSpeed() * (rand() % 40);
}

Enemy::Enemy(const Enemy& a) :  ACharacter(a._name, a._type, a._hp,
a._speed, a._width, a._height, a._x, a._y, a._weapon->clone()),
				_cyclesToMove(a._cyclesToMove),
				_cyclesToShoot(a._cyclesToShoot)
{
}

Enemy& Enemy::operator=(Enemy& a)
{
	ACharacter::operator=(a);
	_cyclesToMove = a._cyclesToMove;
	_cyclesToShoot = a._cyclesToShoot;
	return (*this);
}

Enemy::~Enemy() {
}

IGameEntity*	Enemy::clone() const {
	Enemy* cl = new Enemy(*this);
	return cl;
}

void			Enemy::move() {
	if (_cyclesToMove > 0) {
		_cyclesToMove--;
		return;
	}
	_y -= 1;
	srand ( time(NULL) );
	int shift = rand() % 3 - 1;
	if (this->getX() + shift < 0 || this->getX() + shift >= MAP_WIDTH)
		return;
	_x += shift;
	_cyclesToMove = this->getSpeed();
}

AAmunition		*Enemy::shoot(void) {
	if (_cyclesToShoot > 0) {
		_cyclesToShoot--;
		return (nullptr);
	}
	srand ( time(NULL) );
	_cyclesToShoot = this->getSpeed() * (rand() % 20);
	AAmunition	*am = _weapon->shoot(DOWN);
	if (!am)
		return (nullptr);
	am->setX(this->_x + this->_width / 2);
	am->setY(this->_y - this->_height);
	return (am);
}

int				Enemy::getDamage() const {
	return 40;
}