
#include "AAmunition.hpp"

AAmunition::AAmunition() :
	_type("unknown"),
	_speed(0),
	_direction(0),
	_damage(0),
	_width(1),
	_height(1),
	_x(0),
	_y(0),
	_cyclesToMove(0)
{
}

AAmunition::AAmunition(std::string type, int speed, int direction,
	int damage, int width, int height, int x,
	int y) :
	_type(type),
	_speed(speed),
	_direction(direction),
	_damage(damage),
	_width(width),
	_height(height),
	_x(x),
	_y(y),
	_cyclesToMove(speed)
{

}
AAmunition::~AAmunition(void)
{
}
AAmunition::AAmunition(const AAmunition &other) {
	*this = other;
}
AAmunition &AAmunition::operator = (const AAmunition &other) {
	_type = other._type;
	_speed = other._speed;
	_direction = other._direction;
	_direction = other._direction;
	_damage = other._damage;
	_width = other._width;
	_height = other._height;
	_x = other._x;
	_y = other._y;
	_cyclesToMove = other._cyclesToMove;
	return *this;
}

int				AAmunition::getX() const { return _x; } 
int				AAmunition::getY() const { return _y; } 
void			AAmunition::setX(int x) { _x = x; }
void			AAmunition::setY(int y) { _y = y; }
int				AAmunition::getWidth() const { return _width; } 
int				AAmunition::getHeight() const { return _height; } 
int				AAmunition::getSpeed() const { return _speed; } 
int				AAmunition::getDamage() const { return _damage; }
int				AAmunition::getDirection() const { return _direction; }
std::string		AAmunition::getName() const { return("Bullet"); }
int				AAmunition::getHP() const { return(0); }

void			AAmunition::move() {
	if (getDirection() == UP)
		setY(getY() + 1);
	else
		setY(getY() - 1);
}
AAmunition*		AAmunition::shoot(void) { return nullptr; }
void			AAmunition::setDamage(int damage) { (void)damage; }
std::string		AAmunition::getType() const { return _type; }