#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include "AAmunition.hpp"

class AWeapon {

protected:
	int				_reloading;
	int				_reloading_time;


public:

	AWeapon();
	AWeapon(int reloading, int reloading_time);
	AWeapon(const AWeapon& a);
	virtual ~AWeapon();
	AWeapon& operator=(AWeapon& a); 

	virtual AAmunition		*shoot(int direction) = 0;
	virtual AWeapon			*clone() const = 0;
};

#endif
