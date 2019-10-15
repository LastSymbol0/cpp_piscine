/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:26:15 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:23:19 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_HPP
# define GKRELLM_HPP

// #include "IMonitorDisplay.hpp"
# include "TermDisplay.hpp"
# include "GuiDisplay.hpp"
# include "ncurses.h"

class GKrellM
{
private:
	TermDisplay		_term;
	GuiDisplay		_gui;

	GKrellM(GKrellM const & arg);
	GKrellM &	operator=(GKrellM const & arg);


public:
	GKrellM();
	~GKrellM();

	void		loop();
};

#endif /* GKRELLM_HPP */
