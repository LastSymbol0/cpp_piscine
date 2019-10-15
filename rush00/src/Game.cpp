#include "Game.hpp"

Game::Game(void) :
				_player(nullptr),
				_isPlaying(false),
				_entitiesNumber(0),
				_cyclesNumber(0),
				_cyclesToNextEnemy(0)
{
	for (size_t i = 0; i < LIST_SIZE; i++) {
		_list[i] = nullptr;
	}
}
Game::~Game(void) {
	this->forEachInMap(&Game::removeEntity);
}
Game::Game(const Game &other) {
	*this = other;
}
Game &Game::operator= (const Game &other) {
	this->forEachInMap(&Game::removeEntity);
	this->_player = other._player->clone();
	this->_entitiesNumber = other.getEntitiesNumber();
	for (size_t i = 0; i < LIST_SIZE; i++) {
		this->_list[i] = (other._list[i])->clone();
		if (this->_list[i]->getType() == "player")
			this->_player = this->_list[i];
	}
	return *this;
}


void			Game::play() {

	_isPlaying = true;
	this->gameCycle();
}

void			Game::finish() {
	if (_isPlaying) {
		mvprintw(MAP_HEIGHT - MAP_HEIGHT/2 - 2, MAP_WIDTH/2 + 1 - 7, "---GAME OVER----");
		while (getch() != 'q' || getch() != 27)
			usleep(1000);
		endwin();
	}
}

void			Game::input()
{
	switch (getch())
	{
		case 32: // space
			addEntity(_player->shoot());
			break;
		case KEY_RIGHT: // right arrow
			if (_player->getX() + 5 < MAP_WIDTH)
				_player->setX(_player->getX() + 1);
			break;
		case KEY_LEFT: // left arrow
			if (_player->getX() > 0)
				_player->setX(_player->getX() - 1);
			break;
		case 27: // escape
		case 'q':
			endwin();
			exit (0);
			break;
		default:
			break;
	}
}

int				Game::redraw(IGameEntity *entity)
{
	if (entity == nullptr)
		return 0;
	attron (COLOR_PAIR(4));	
	move(MAP_HEIGHT - entity->getY() - 1,entity->getX());
	if (entity->getType() == "player") {
		attron (COLOR_PAIR(3));
		mvprintw(MAP_HEIGHT - entity->getY(), entity->getX() + 2, "|");
		mvprintw(MAP_HEIGHT - entity->getY() + 1, entity->getX() + 1, "/");
		mvprintw(MAP_HEIGHT - entity->getY() + 1, entity->getX() + 2, "H");
		mvprintw(MAP_HEIGHT - entity->getY() + 1, entity->getX() + 3, "\\");
		mvprintw(MAP_HEIGHT - entity->getY() + 2, entity->getX() + 1, "H");
		mvprintw(MAP_HEIGHT - entity->getY() + 2, entity->getX(), "/");
		mvprintw(MAP_HEIGHT - entity->getY() + 2, entity->getX() + 3, "H");
		mvprintw(MAP_HEIGHT - entity->getY() + 2, entity->getX() + 4, "\\");

	}
	else if (entity->getType() == "bullet") {
		attron (COLOR_PAIR(5));	
		addch('*');
	}
	else  {
		mvprintw(MAP_HEIGHT - entity->getY(), entity->getX(), "V");
		mvprintw(MAP_HEIGHT - entity->getY(), entity->getX() + 1, "V");
		mvprintw(MAP_HEIGHT - entity->getY(), entity->getX() + 2, "V");
		mvprintw(MAP_HEIGHT - entity->getY() + 1, entity->getX() + 1, "V");
	}
	
	return 1;
}

void			Game::draw_background()
{
	static int	line = 1;
	int			i_line;
	static int	wait = BACKGROUND_MOVE;

	if (line >= 53)
		line = 0;
	for (int i = 0; i <= 54; i++) {
		for (int j = 0; j < 100; j++)
		{
			move(i,j);
			i_line = i - line;
			if (i_line <= 0)
				i_line += 53;
			if (img[i_line][j] == '#')
				attron (COLOR_PAIR(1));
			else
				attron (COLOR_PAIR(2));
			addch(img[i_line][j] | A_LOW);
		}
	}
	wait--;
	if (wait <= 0) {
		wait = BACKGROUND_MOVE;
		line++;
	}
	attron (COLOR_PAIR(6));
	mvprintw(54, 0, "\tPlayer: %s; hp:%d;\t\t\t\t\t\t\t\t\t\t", _player->getName().c_str(), _player->getHP());
}

void			Game::gameCycle() {
	_isPlaying = true;
	while (_isPlaying && _entitiesNumber && _player != nullptr) {
		if (Game::incursis) {
			draw_background();
			input();
		}
		_cyclesNumber++;
		if (_cyclesNumber % 10 == 0){
			if (!Game::incursis)
				addEntity(_player->shoot());
			forEachInMap(&Game::makeMove);
			createEnemy();
		}
		if (Game::incursis)
			forEachInMap(&Game::redraw);
		refresh();
		usleep(3000);
	}
	this->finish();
}

int				Game::forEachInMap(int (Game::*func)(IGameEntity *entity)) {
	int	result = 0;
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] != nullptr)
			result += (this->*func)(_list[i]);
	}
	return result;
}

int				Game::makeMove(IGameEntity *entity) {
	if (entity == nullptr)
		return 0;
	entity->move();
	int isRemoved = trackCollision(entity);
	if (!isRemoved && entity->getType() != "player")
		addEntity(entity->shoot());
	return 1;
}

int				Game::trackCollision(IGameEntity *entity) {
	if (!entity)
		return 0;
	if (entity->getX() < 0 || entity->getX() + entity->getWidth() > MAP_WIDTH ||
	entity->getY() - entity->getHeight() < 0 || entity->getY() >= MAP_HEIGHT) {
		removeEntity(entity);
		return 1;
	}
	if (entity->getY() == 0 && entity->getType() != "player") {
		removeEntity(entity);
		return 1;
	}
	IGameEntity *place = nullptr;
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] != nullptr && _list[i] != entity && collision(_list[i], entity))
		{
			place = _list[i];
			break;
		}
	}
	if (place != nullptr && place != entity) {
		resolveColision(entity, place);
		return 1;
	}
	return 0;
}

int				Game::resolveColision(IGameEntity *e1, IGameEntity *e2) {
	int result = 0;
	if (!e1 || !e2)
		return 0;
	e1->setDamage(e2->getDamage());
	e2->setDamage(e1->getDamage());
	if (e2->getHP() <= 0)
		removeEntity(e2);
	if (e1->getHP() <= 0)
		result = removeEntity(e1);
	else {
		if (e1->getType() != "player")
			result = removeEntity(e1);
		else
			removeEntity(e2);
	}
	return result;
}

void			Game::addEntity(IGameEntity *entity) {
	if (!entity)
		return;
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] != nullptr && collision(_list[i], entity)) {
			delete entity;
			return;
		}
	}
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] == nullptr) {
			_list[i] = entity;
			this->_entitiesNumber++;
			if (entity->getType() == "player" &&
			this->_player == nullptr)
				this->_player = entity;
			return;
		}
	}
	delete entity;
}

IGameEntity		*Game::getEntity(int x, int y) {
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] != nullptr && collision(_list[i], x, y))
			return _list[i];
	}
	return nullptr;
}


int				Game::getEntity(IGameEntity *entity) {
	for (size_t i = 0; i < LIST_SIZE; i++) {
		if (_list[i] == entity)
			return i;
	}
	return -1;
}

bool			Game::collision(IGameEntity *e1, IGameEntity *e2) {
	bool hor = false;
	bool ver = false;
	if (e1->getX() >= e2->getX() && e1->getX() <= e2->getX() + e2->getWidth() - 1)
		hor = true;
	else if (e2->getX() >= e1->getX() && e2->getX() <= e1->getX() + e1->getWidth() - 1)
		hor = true;
	if (e1->getY() <= e2->getY() && e1->getY() >= e2->getY() - e2->getHeight() + 1)
		ver = true;
	else if (e2->getY() <= e1->getY() && e2->getY() >= e1->getY() - e1->getHeight() + 1)
		ver = true;
	return (hor && ver);
}

bool			Game::collision(IGameEntity *e1, int x, int y) {
	return (x >= e1->getX() && x <= e1->getX() + e1->getWidth() - 1 && 
	y >= e1->getY() && y <= e1->getY() - e1->getHeight() + 1);
}

int				Game::removeEntity(IGameEntity *entity) {
	if (!entity)
		return 0;
	if (entity == _player)
		_player = nullptr;
	int	i = getEntity(entity);
	if (i == -1)
		return 0;
	_list[i] = nullptr;
	delete entity;
	this->_entitiesNumber--;
	return 1;
}

int				Game::removeEntity(int x, int y) {
	return removeEntity(getEntity(x, y));
}

void			Game::createPlayer(std::string const &name) {
	Player	*p = new Player(name);
	addEntity(p);
}

void			Game::createEnemy()  {
	if (_cyclesToNextEnemy > 0) {
		_cyclesToNextEnemy--;
		return;
	}
	for (size_t j = 0; j < MAP_WIDTH; j++) {
		if (getEntity(j, MAP_HEIGHT - 1) != nullptr) {
			return;
		}
	}
	srand ( time(NULL) );
	Enemy *e = new Enemy(rand() % (MAP_WIDTH - 3), MAP_HEIGHT);
	addEntity(e);
	srand ( time(NULL) );
	_cyclesToNextEnemy = rand() % 100;
}

int				Game::getEntitiesNumber() const {
	return this->_entitiesNumber;
}