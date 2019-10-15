#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ACharacter.hpp"
#include "Gun.hpp"
#include "ft_retro.hpp"

class Player : public ACharacter {

private:

public:
	Player();
	Player(std::string const &name);
	Player(const Player& a);
	~Player();
	Player& operator=(Player& a); 

	AAmunition*		shoot(void);
	IGameEntity*	clone() const;
	void			move();
	int				getDamage() const ;
};

#endif
