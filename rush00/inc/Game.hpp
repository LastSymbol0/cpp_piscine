#ifndef GAME_HPP
# define GAME_HPP

# include "AWeapon.hpp"
# include "ACharacter.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "ft_retro.hpp"

# define LIST_SIZE (MAP_HEIGHT * MAP_WIDTH / 4)
# define BEAT_LEFT_BOUNDARY(x, i, size) (x < 0 && (i - x) % size + x < 0)
# define BEAT_RIGHT_BOUNDARY(x, i, size) (x > 0 && i % size == 0)

class Game {

private:

	IGameEntity		*_player;
	IGameEntity		*_list[LIST_SIZE];
	bool			_isPlaying;
	unsigned int	_entitiesNumber;
	unsigned int	_cyclesNumber;
	int				_cyclesToNextEnemy;

	void			gameCycle();
	int				makeMove(IGameEntity *entity);
	int				forEachInMap(int (Game::*func)(IGameEntity *));
	int				trackCollision(IGameEntity *entity);
	int				resolveColision(IGameEntity *e1, IGameEntity *e2);
	// IGameEntity		*isThereEntity(IGameEntity *entity);
	// IGameEntity		*isThereEntity(int x, int y);
	bool			collision(IGameEntity *e1, int x, int y);
	bool			collision(IGameEntity *e1, IGameEntity *e2);

public:

	Game(void);
	~Game(void);
	Game(const Game &other);
	Game &operator= (const Game &other);

	int				redraw(IGameEntity *entity);
	void			draw_background();
	void			input();
	void			play();
	void			finish();
	void			addEntity(IGameEntity *entity);
	IGameEntity		*getEntity(int x, int y);
	int				getEntity(IGameEntity *entity);
	int				removeEntity(IGameEntity *entity);
	int				removeEntity(int x, int y);
	void			createPlayer(std::string const &name);
	int				getEntitiesNumber() const;
	void			createEnemy();
	
	const static bool	incursis = true;

};

#endif
