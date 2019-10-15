#include "Player.hpp"

Player::Player() : ACharacter("player", "player", 100, 0, 5, 3, MAP_WIDTH / 2 - 2, 4, new Gun())
{
}

Player::Player(std::string const& name) : ACharacter(name, "player", 100, 0, 5, 3, MAP_WIDTH / 2 - 2, 4, new Gun())
{
}

Player::Player(const Player& a) : ACharacter(a)
{
}

Player& Player::operator=(Player& a)
{
	ACharacter::operator=(a);
	return (*this);
}

Player::~Player() {
}

AAmunition	*Player::shoot(void) {
	AAmunition	*am = _weapon->shoot(UP);
	if (!am)
		return (nullptr);
	am->setX(this->_x + this->getWidth() / 2);
	am->setY(this->_y + 1);
	return (am);
	return (nullptr);
}

IGameEntity*	Player::clone() const {
	Player* cl = new Player(*this);
	return cl;
}

void			Player::move() {}

int				Player::getDamage() const {
	return 40;
}