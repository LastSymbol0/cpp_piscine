
#include "ACharacter.hpp"

ACharacter::ACharacter() :
										_name("unknown"),
										_type("unknown"),
										_hp(0),
										_speed(0),
										_width(1),
										_height(1),
										_x(0),
										_y(0),
										_weapon(nullptr)
{
}
ACharacter::ACharacter(std::string const &name, std::string const &type, int hp,
unsigned int speed, int width, int height, int x, int y, AWeapon *weapon) :
										_name(name),
										_type(type),
										_hp(hp),
										_speed(speed),
										_width(width),
										_height(height),
										_x(x),
										_y(y),
										_weapon(weapon)
{
}

ACharacter::~ACharacter(void)
{
	if (_weapon)
		delete _weapon;
}
ACharacter::ACharacter(const ACharacter &other)
{
	*this = other;
}
ACharacter &ACharacter::operator = (const ACharacter &other)
{
	if (_weapon)
		delete _weapon;
	_name = other._name;
	_type = other._type;
	_hp = other._hp;
	_speed = other._speed;
	_width = other._width;
	_height = other._height;
	_x = other._x;
	_y = other._y;
	if (other._weapon)
		_weapon = other._weapon->clone();
	else
		_weapon = nullptr;
	return *this;
}

std::string		ACharacter::getName() const { return _name; }
int				ACharacter::getHP() const { return _hp; }
int				ACharacter::getX() const { return _x; }
int				ACharacter::getY() const { return _y; }
void			ACharacter::setX(int x) { _x = x; }
void			ACharacter::setY(int y) { _y = y; }
int				ACharacter::getWidth() const { return _width; }
int				ACharacter::getHeight() const { return _height; }
int				ACharacter::getSpeed() const { return _speed; }
std::string		ACharacter::getType() const { return _type; }
void			ACharacter::setDamage(int damage) {
	if (damage > 0 && _hp > 0) {
		_hp -= damage;
		if (_hp < 0)
			_hp = 0;
	}
}
