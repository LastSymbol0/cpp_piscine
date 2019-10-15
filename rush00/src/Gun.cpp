
#include "Gun.hpp"
# include <iostream>

Gun::Gun() : AWeapon(0, 0)
{
}

Gun::Gun(const Gun& a) : AWeapon(a._reloading, a._reloading_time)
{
}

Gun& Gun::operator=(Gun& a)
{
	AWeapon::operator=(a);
	return (*this);
}

Gun::~Gun() {
}

AAmunition*	Gun::shoot(int direction) {
	if (_reloading == 0) {
		_reloading = _reloading_time;
		return (new Bullet(direction));
	}
	_reloading -=20;
	return nullptr;
}

AWeapon*	Gun::clone() const {
	Gun	*cl = new Gun(*this);
	return cl;
}
