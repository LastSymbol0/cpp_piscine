#ifndef AAMUNITION_HPP
# define AAMUNITION_HPP

# include "IGameEntity.hpp"

enum {UP, DOWN};

class AAmunition : public IGameEntity {

protected:

	std::string		_type;
	int				_speed;
	int				_direction;
	int				_damage;

	int				_width;
	int				_height;
	int				_x;
	int				_y;
	int				_cyclesToMove;

public:

	AAmunition();
	AAmunition(std::string type, int speed, int direction,
	int damage, int width, int height, int x,
	int y);
	AAmunition(const AAmunition& a);
	virtual ~AAmunition();
	AAmunition& operator=(const AAmunition& a); 

	int				getX() const ;
	int				getY() const ;
	void			setX(int x) ;
	void			setY(int y) ;
	int				getWidth() const ;
	int				getHeight() const ;
	int				getDamage() const ;
	int				getDirection() const ;
	int				getSpeed() const ;
	std::string		getName() const ;
	int				getHP() const ;
	void			move();
	AAmunition*		shoot(void);
	void			setDamage(int damage);
	std::string		getType() const ;

};

#endif
