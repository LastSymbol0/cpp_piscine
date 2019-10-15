#include "Game.hpp"
#include "ft_retro.hpp"

void		init_ncurses()
{
	initscr();
	keypad(stdscr, true);
	start_color();
	init_pair (1, COLOR_WHITE, COLOR_YELLOW);
	init_pair (2, COLOR_CYAN, COLOR_YELLOW);
	init_pair (3, COLOR_BLACK, COLOR_RED);
	init_pair (4, COLOR_RED, COLOR_BLACK);
	init_pair (5, COLOR_RED, COLOR_BLACK);
	init_pair (6, COLOR_MAGENTA, COLOR_BLACK);
	resizeterm(MAP_WIDTH, MAP_HEIGHT);
	resize_term(MAP_WIDTH, MAP_HEIGHT);
	curs_set(FALSE);
	endwin();
	clear();
}


std::string			begin()
{
	std::string		name;
	char ch = ' ';

	echo();
	mvprintw(15, 0, "\tPlease, input player name: ");
	while (ch != '\n')
	{	
		name.push_back(ch);
		ch = getch();
	}
	name = name.substr(3, 35);
	noecho();
	nodelay(stdscr, TRUE);
	return (name);
}

int			main(void) 
{
	Game	*game = new Game;

	if (Game::incursis) {
		init_ncurses();
		game->createPlayer(begin());
	} else {
		game->createPlayer("Name");
	}
	
	game->play();
	clear();
	delete game;
	return 0;
}