/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:03:44 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 18:54:30 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static SDL_Window		*ft_windowed(SDL_Window *win, t_sdl *sdl)
{
	if (!(win = SDL_CreateWindow("FORAINSTEIN",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			sdl->res_width,
			sdl->res_hight,
			SDL_WINDOW_SHOWN
			| SDL_WINDOW_ALWAYS_ON_TOP)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (win);
}

static SDL_Window		*ft_windowed_resize_full(SDL_Window *win, t_sdl *sdl)
{
	if (!(win = SDL_CreateWindow("FORAINSTEIN",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			sdl->w_max,
			sdl->h_max,
			SDL_WINDOW_SHOWN
			| SDL_WINDOW_MAXIMIZED
			| SDL_WINDOW_ALWAYS_ON_TOP)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (win);
}

static SDL_Window		*ft_fullscren(SDL_Window *win, t_sdl *sdl)
{
	if (!(win = SDL_CreateWindow("FORAINSTEIN",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			(int)sdl->res_width,
			(int)sdl->res_hight,
			SDL_WINDOW_SHOWN
			| SDL_WINDOW_FULLSCREEN
			| SDL_WINDOW_ALWAYS_ON_TOP)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (win);
}

static SDL_Window		*ft_fullscren_maxres(SDL_Window *win, t_sdl *sdl)
{
	if (!(win = SDL_CreateWindow("FORAINSTEIN",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			sdl->w_max,
			sdl->h_max,
			SDL_WINDOW_SHOWN
			| SDL_WINDOW_FULLSCREEN_DESKTOP
			| SDL_WINDOW_ALWAYS_ON_TOP)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (win);
}

SDL_Window		*ft_create_window(t_sdl *sdl)
{
	SDL_Window *win;

	win = NULL;
	if (sdl->windowed == 1)
		win = ft_windowed(win, sdl);
	if (sdl->windowed_resize_full == 1)
		win = ft_windowed_resize_full(win, sdl);
	if (sdl->fullscreen == 1)
		win = ft_fullscren(win, sdl);
	if (sdl->fullscreen_maxres == 1)
		win = ft_fullscren_maxres(win, sdl);
	return (win);
}
