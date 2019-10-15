
#include "AWeapon.hpp"

AWeapon::AWeapon() :
							_reloading(0),
							_reloading_time(0)
{
}

AWeapon::AWeapon(int reloading, int reloading_time) :
							_reloading(reloading),
							_reloading_time(reloading_time)
{
}

AWeapon::AWeapon(const AWeapon& a) :
							_reloading(a._reloading),
							_reloading_time(a._reloading_time)
{
}

AWeapon& AWeapon::operator=(AWeapon& a)
{
	_reloading = a._reloading;
	_reloading_time = a._reloading_time;
	return (*this);
}

AWeapon::~AWeapon() {
}
