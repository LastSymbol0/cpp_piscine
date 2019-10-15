#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

# include <string.h>
# include <iostream>

class	ACharacter;
class	AAmunition;

class IGameEntity {

private:

public:

	virtual ~IGameEntity(void) {}
	virtual std::string		getName() const = 0;
	virtual std::string		getType() const = 0;
	virtual int				getHP() const = 0;
	virtual int				getX() const = 0;
	virtual int				getY() const = 0;
	virtual void			setX(int x) = 0;
	virtual void			setY(int y) = 0;
	virtual int				getWidth() const = 0;
	virtual int				getHeight() const = 0;
	virtual void			move() = 0;
	virtual AAmunition*		shoot() = 0;
	// virtual FunPtr			getAction() const = 0;
	virtual int				getSpeed() const = 0;
	// virtual ACharacter		*getTarget() const = 0;
	virtual int				getDamage() const = 0;
	virtual void			setDamage(int damage) = 0;
	virtual IGameEntity*	clone() const = 0;

};

#endif
