/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nk_implementation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:52:49 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 15:52:55 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define NK_IMPLEMENTATION
# define NK_SDL_GL2_IMPLEMENTATION
# include "nuklear/nuklear.h"
# include "nuklear/demo/sdl_opengl2/nuklear_sdl_gl2.h"
