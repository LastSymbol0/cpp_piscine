#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ACharacter.hpp"
# include "Gun.hpp"
# include "ft_retro.hpp"

class Enemy : public ACharacter {

private:

	int		_cyclesToMove;
	int		_cyclesToShoot;

public:

	Enemy();
	Enemy(int x, int y);
	Enemy(const Enemy& a);
	~Enemy();
	Enemy& operator=(Enemy& a);

	IGameEntity*	clone() const;
	void			move();
	AAmunition		*shoot(void);
	int				getDamage() const ;

};

#endif
