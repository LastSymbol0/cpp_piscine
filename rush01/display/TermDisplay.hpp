/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TermDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:32:35 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 13:32:40 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMDISPLAY_HPP
# define TERMDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "ncurses.h"
# define W_WIDTH 90
# define W_HEIGHT 60

class TermDisplay : public IMonitorDisplay
{
private:
	TermDisplay(TermDisplay const & arg);
	TermDisplay &	operator=(TermDisplay const & arg);
public:
	TermDisplay();
	~TermDisplay();

	void		init_ncurses();

	virtual void	draw();
	void			draw_grid();
	virtual void	draw_os();
	virtual void	draw_hostname();
	virtual void	draw_date();
	virtual void	draw_cpu();
	virtual void	draw_ram();
	virtual void	draw_net();
};

#endif /* TERMDISPLAY_HPP */
