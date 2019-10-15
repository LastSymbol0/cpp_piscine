#ifndef GUN_HPP
# define GUN_HPP

# include "AWeapon.hpp"
# include "Bullet.hpp"

class Gun : public AWeapon {

protected:

public:

	Gun();
	Gun(const Gun& a);
	virtual ~Gun();
	Gun& operator=(Gun& a); 

	AAmunition*		shoot(int direction);
	AWeapon			*clone() const;
};

#endif
