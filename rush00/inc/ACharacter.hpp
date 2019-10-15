#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP
# include "IGameEntity.hpp"
# include "AWeapon.hpp"

class ACharacter : public IGameEntity {

protected:

	std::string		_name;
	std::string		_type;
	int				_hp;
	unsigned int	_speed;

	int				_width;
	int				_height;
	int				_x;
	int				_y;

	void			(ACharacter::*_action)();
	AWeapon			*_weapon;


public:

	ACharacter();
	ACharacter(std::string const &name, std::string const &type,
	int hp, unsigned int speed, int width, int height, int x, int y, AWeapon *_weapon);
	ACharacter(const ACharacter& a);
	virtual ~ACharacter();
	ACharacter& operator=(const ACharacter& a); 

	std::string				getName() const ;
	std::string				getType() const;
	int						getHP() const ;
	int						getX() const ;
	int						getY() const ;
	void					setX(int x);
	void					setY(int y);
	int						getWidth() const ;
	int						getHeight() const ;
	int						getSpeed() const ;
	virtual int				getDamage() const = 0;
	int						getDirection() const ;
	virtual IGameEntity*	clone() const = 0;
	virtual void			move() = 0;
	virtual AAmunition		*shoot(void) = 0;
	void					setDamage(int damage);
};

#endif
