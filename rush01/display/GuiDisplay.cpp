/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GuiDisplay.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:41:07 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 15:41:09 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GuiDisplay.hpp"
#include "stdlib.h"

GuiDisplay::GuiDisplay()
{
	win = SDL_CreateWindow("Info", 200, 200, G_W_WIDTH, G_W_HEIGHT,
	SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	gl_context = SDL_GL_CreateContext(win);
	ctx = nk_sdl_init(win);
	bg.r = 0.10f;
	bg.g = 0.18f;
	bg.b = 0.24f;
	bg.a = 1.0f;

	struct nk_font_atlas	*atlas;
	struct nk_font			*droid;
	nk_sdl_font_stash_begin(&atlas);
	droid = nk_font_atlas_add_from_file(atlas,
					"./nuklear/extra_font/DroidSans.ttf", 14, 0);
	nk_sdl_font_stash_end();
	nk_style_set_font(ctx, &droid->handle);
}

GuiDisplay::~GuiDisplay() {}

void		GuiDisplay::draw() {
	evt();
	draw_os();
	draw_hostname();
	draw_date();
	draw_cpu();
	draw_ram();
	draw_net();
		// overview(ctx);

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(bg.r, bg.g, bg.b, bg.a);
	nk_sdl_render(NK_ANTI_ALIASING_ON);
	SDL_GL_SwapWindow(win);
}

void		GuiDisplay::evt() {
	SDL_Event		evt;

	nk_input_begin(ctx);
	while (SDL_PollEvent(&evt))
	{
		if (evt.type == SDL_QUIT || SDL_SCANCODE_ESCAPE == evt.key.keysym.scancode)
			nk_exit();
	}
	nk_input_end(ctx);
}

void		GuiDisplay::draw_os() {
	const char *os = _os_m.getOS().c_str();
	const char *version = _os_m.getVersion().c_str();

	if (nk_begin(ctx, "OS module", nk_rect(430, 10, 200, 100),
		NK_WINDOW_BORDER | NK_WINDOW_SCALABLE | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "OS module", NK_TEXT_CENTERED);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "OS:", NK_TEXT_LEFT);
		nk_label(ctx, os, NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "version:", NK_TEXT_LEFT);
		nk_label(ctx, version, NK_TEXT_LEFT);
		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::draw_hostname() {
	const char *host = _hostname_m.getHost_name().c_str();
	const char *user = _hostname_m.getUser_name().c_str();

	if (nk_begin(ctx, "Host module", nk_rect(220, 10, 200, 100),
		NK_WINDOW_BORDER | NK_WINDOW_SCALABLE | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "Host module", NK_TEXT_CENTERED);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Host:", NK_TEXT_LEFT);
		nk_label(ctx, host, NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "User:", NK_TEXT_LEFT);
		nk_label(ctx, user, NK_TEXT_LEFT);
		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::draw_date() {
	_date_m.refresh();
	const char *date = _date_m.getDate().c_str();
	const char *time = _date_m.getTime().c_str();

	if (nk_begin(ctx, "Date module", nk_rect(10, 10, 200, 100),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "Date/time module", NK_TEXT_CENTERED);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Date:", NK_TEXT_LEFT);
		nk_label(ctx, date, NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Time:", NK_TEXT_LEFT);
		nk_label(ctx, time, NK_TEXT_LEFT);
		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::draw_cpu() {
	_cpu_m.refresh();
	const char *model = _cpu_m.getName().c_str();
	const char *speed = _cpu_m.getSpeed().c_str();
	int		core_n = atoi(_cpu_m.getNumberCore().c_str());
	float idle = _cpu_m.getIdle();
	float user = _cpu_m.getUser();
	float sys = _cpu_m.getSys();

	if (nk_begin(ctx, "CPU module", nk_rect(10, 120, 300, 240),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "CPU module", NK_TEXT_CENTERED);


		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Model:", NK_TEXT_LEFT);
		nk_label(ctx, model, NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Number of cores:", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(core_n).c_str(), NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Frequency:", NK_TEXT_LEFT);
		nk_label(ctx, speed, NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 20, 1);
		nk_label(ctx, "    Usage", NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "User:", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(user).substr(0,5).c_str(), NK_TEXT_LEFT);
		size_t user_p = static_cast<size_t>(user);
		nk_progress(ctx, &user_p, 100, NK_MODIFIABLE);


		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "System:", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(sys).substr(0,5).c_str(), NK_TEXT_LEFT);
		size_t sys_p = static_cast<size_t>(sys);
		nk_progress(ctx, &sys_p, 100, NK_MODIFIABLE);

		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "Idle:", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(idle).substr(0,5).c_str(), NK_TEXT_LEFT);
		size_t idle_p = static_cast<size_t>(idle);
		nk_progress(ctx, &idle_p, 100, NK_MODIFIABLE);

		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::draw_ram() {
	_ram_m.refresh();

	int used = atoi(_ram_m.getUsed().c_str());
	int wired = atoi(_ram_m.getWired().c_str());
	int unused = atoi(_ram_m.getUnused().c_str());

	if (nk_begin(ctx, "RAM module", nk_rect(320, 120, 310, 160),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "RAM module", NK_TEXT_CENTERED);


		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Total memory: ", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(used + unused).c_str(), NK_TEXT_LEFT);

		// nk_layout_row_dynamic(ctx, 20, 1);
		// nk_label(ctx, "    Usage", NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "Used: ", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(used).c_str(), NK_TEXT_LEFT);
		size_t used_p = (static_cast<float>(used) / (used + unused)) * 100;
		nk_progress(ctx, &used_p, 100, NK_MODIFIABLE);

		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "Wired: ", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(wired).c_str(), NK_TEXT_LEFT);
		size_t wired_p = (static_cast<float>(wired) / (used + unused)) * 100;
		nk_progress(ctx, &wired_p, 100, NK_MODIFIABLE);

		nk_layout_row_dynamic(ctx, 20, 3);
		nk_label(ctx, "Unused: ", NK_TEXT_LEFT);
		nk_label(ctx, std::to_string(unused).c_str(), NK_TEXT_LEFT);
		size_t unused_p = (static_cast<float>(unused) / (used + unused)) * 100;
		nk_progress(ctx, &unused_p, 100, NK_MODIFIABLE);
		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::draw_net() {
	_net_m.refresh();
	const char *in = _net_m.getIn_p().c_str();
	const char *out = _net_m.getOut_p().c_str();


	if (nk_begin(ctx, "Net module", nk_rect(320, 290, 310, 130),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE))
	{
		nk_layout_row_dynamic(ctx, 30, 1);
		nk_label(ctx, "Network module", NK_TEXT_CENTERED);

		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Packets:", NK_TEXT_CENTERED);

		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "In:", NK_TEXT_RIGHT);
		nk_label(ctx, in, NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 20, 2);
		nk_label(ctx, "Out:", NK_TEXT_RIGHT);
		nk_label(ctx, out, NK_TEXT_LEFT);

		nk_end(ctx);
	}
	return ;
}

void		GuiDisplay::nk_exit()
{
	nk_clear(ctx);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(win);
	SDL_Quit();
	nk_sdl_shutdown();
	exit(1);
}

