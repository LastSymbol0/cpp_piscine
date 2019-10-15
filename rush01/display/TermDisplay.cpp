/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TermDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:32:43 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 13:32:45 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TermDisplay.hpp"
#include <iostream>
#include <string>

TermDisplay::TermDisplay()
{
	init_ncurses();
}

TermDisplay::~TermDisplay() {}

void		TermDisplay::draw() {
	clear();
	curs_set(FALSE);
	attron(COLOR_PAIR(4));
	draw_grid();
	const char *title = "Our awesome system monitor";
	mvprintw(1, (W_WIDTH - 26) /2 , title);	
	draw_os();
	draw_hostname();
	draw_date();
	draw_cpu();
	draw_ram();
	draw_net();
	refresh();
}

void		TermDisplay::draw_grid() {
	for (size_t i = 0; i < W_WIDTH ; i++) {
		mvprintw(0, i, "-");
		mvprintw(2, i, "-");
		mvprintw(7, i, "-");
		mvprintw(17, i, "-");
	}
	return ;
}

void		TermDisplay::draw_os() {
	const char *os = _os_m.getOS().c_str();
	const char *version = _os_m.getVersion().c_str();

	attron(COLOR_PAIR(3));
	mvprintw(3, 60, "OS:");
	mvprintw(4, 60, "\t%s", os);
	mvprintw(5, 60, "Version:");
	mvprintw(6, 60, "\t%s", version);
	return ;
}
void		TermDisplay::draw_hostname() {
	const char *host = _hostname_m.getHost_name().c_str();
	const char *user = _hostname_m.getUser_name().c_str();

	attron(COLOR_PAIR(2));
	mvprintw(3, 30, "User:");
	mvprintw(4, 30, "\t%s", user);
	mvprintw(5, 30, "Host:");
	mvprintw(6, 30, "\t%s", host);
	return ;
}
void		TermDisplay::draw_date() {
	_date_m.refresh();
	const char *date = _date_m.getDate().c_str();
	const char *time = _date_m.getTime().c_str();

	attron(COLOR_PAIR(1));
	mvprintw(3, 0, "Date:");
	mvprintw(4, 0, "\t%s", date);
	mvprintw(5, 0, "Time:");
	mvprintw(6, 0, "\t%s", time);
	return ;
}

void	TermDisplay::draw_cpu() {
	_cpu_m.refresh();
	const char *model = _cpu_m.getName().c_str();
	const char *speed = _cpu_m.getSpeed().c_str();
	int		core_n = atoi(_cpu_m.getNumberCore().c_str());
	float	idle = _cpu_m.getIdle();
	float	user = _cpu_m.getUser();
	float	sys = _cpu_m.getSys();

	attron(COLOR_PAIR(1));
	mvprintw(9, 2, "CPU");
	mvprintw(10, 4, "Model: %s %s", model, speed);
	mvprintw(11, 4, "Number of cores: %d", core_n);
	mvprintw(12, 2, "Usage:");
	attron(COLOR_PAIR(5));
	mvprintw(13, 0, "\tSys\t%f", sys);
	attron(COLOR_PAIR(2));
	mvprintw(14, 0, "\tUser\t%f", user);
	attron(COLOR_PAIR(4));
	mvprintw(15, 0, "\tIdle\t%f", idle);
	return ;
}

void	TermDisplay::draw_ram() {
	_ram_m.refresh();
	int used = atoi(_ram_m.getUsed().c_str());
	int wired = atoi(_ram_m.getWired().c_str());
	int unused = atoi(_ram_m.getUnused().c_str());

	attron(COLOR_PAIR(2));
	mvprintw(9, 32, "RAM");
	mvprintw(10, 34, "Total: %d MB", used + unused);
	mvprintw(12, 32, "Usage:");
	attron(COLOR_PAIR(5));
	mvprintw(13, 30, "\t\tUsed: %d MB", used);
	attron(COLOR_PAIR(2));
	mvprintw(14, 30, "\t\tWired: %d MB", wired);
	attron(COLOR_PAIR(4));
	mvprintw(15, 30, "\t\tUnused: %d MB", unused);
}

void	TermDisplay::draw_net() {
	_net_m.refresh();
	const char *in = _net_m.getIn_p().c_str();
	const char *out = _net_m.getOut_p().c_str();

	attron(COLOR_PAIR(3));
	mvprintw(9, 62, "Network");
	mvprintw(12, 64, "Packets:");
	attron(COLOR_PAIR(5));
	mvprintw(13, 60, "\t\tIn: %s", in);
	attron(COLOR_PAIR(4));
	mvprintw(14, 60, "\t\tOut: %s", out);
}

void		TermDisplay::init_ncurses()
{
	system("clear");
	initscr();
	keypad(stdscr, true);
	curs_set(FALSE);
	noecho();
	start_color();
	init_pair (1, COLOR_WHITE, COLOR_BLACK);
	init_pair (2, COLOR_CYAN, COLOR_BLACK);
	init_pair (3, COLOR_RED, COLOR_BLACK);
	init_pair (4, COLOR_GREEN, COLOR_BLACK);
	init_pair (5, COLOR_YELLOW, COLOR_BLACK);

	resizeterm(W_WIDTH, W_HEIGHT);
	resize_term(W_WIDTH, W_HEIGHT);
	endwin();
	clear();
}

