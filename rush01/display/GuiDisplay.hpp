/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GuiDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:41:03 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 15:41:04 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIDISPLAY_HPP
# define GUIDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "ft_gkrellm.hpp"
# define G_W_WIDTH 640
# define G_W_HEIGHT 440

class GuiDisplay : public IMonitorDisplay
{
private:
	SDL_Window			*win;
	SDL_GLContext		gl_context;
	struct nk_context	*ctx;
	struct nk_colorf	bg;
		GuiDisplay(GuiDisplay const & arg);
	GuiDisplay &	operator=(GuiDisplay const & arg);
public:
	GuiDisplay(/* args */);
	~GuiDisplay();

	void			draw();
	void			draw_os();
	void			draw_hostname();
	void			draw_date();
	void			draw_cpu();
	void			draw_ram();
	void			draw_net();
	void			evt();
	void			nk_exit();
};

#endif /* GUIDISPLAY_HPP */
