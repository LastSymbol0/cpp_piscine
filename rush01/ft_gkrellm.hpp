/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:11:05 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 16:11:06 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_opengl.h>
# include <OpenGL/gl.h>

/*
** nuklear
*/
# define NK_INCLUDE_FIXED_TYPES
# define NK_INCLUDE_STANDARD_IO
# define NK_INCLUDE_STANDARD_VARARGS
# define NK_INCLUDE_DEFAULT_ALLOCATOR
# define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
# define NK_INCLUDE_FONT_BAKING
# define NK_INCLUDE_DEFAULT_FONT
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <assert.h>
# include <limits.h>
# include "nuklear/nuklear.h"
# include "nuklear/demo/sdl_opengl2/nuklear_sdl_gl2.h"

#endif /* FT_GKRELLM_HPP */
