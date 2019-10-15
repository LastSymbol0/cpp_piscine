/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:26:08 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 13:26:11 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GKrellM.hpp"
#include <unistd.h>

GKrellM::GKrellM() {}

GKrellM::~GKrellM() {}

void		GKrellM::loop() {
	bool running = true;
	nodelay(stdscr, true);

	while (running) {
		_term.draw();
		_gui.draw();
	}
}
