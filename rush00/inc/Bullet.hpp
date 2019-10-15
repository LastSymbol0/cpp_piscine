#ifndef BULLET_HPP
# define BULLET_HPP

#include "AAmunition.hpp"

class Bullet : public AAmunition {

private:

public:
	Bullet();
	Bullet(int x, int y);
	Bullet(int direction);
	Bullet(const Bullet& a);
	virtual ~Bullet();
	Bullet& operator=(Bullet& a); 

	IGameEntity*	clone() const ;
	
};

#endif
