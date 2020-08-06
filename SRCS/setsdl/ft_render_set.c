/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:31:30 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/05 03:30:52 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static struct SDL_Renderer		*h_off_v_off(SDL_Window *win,
							struct SDL_Renderer *ren)
{
	if (!(ren = SDL_CreateRenderer(
			win,
			-1,
			SDL_RENDERER_SOFTWARE)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (ren);
}

static struct SDL_Renderer		*h_off_v_on(SDL_Window *win,
							struct SDL_Renderer *ren)
{
	if (!(ren = SDL_CreateRenderer(
			win,
			-1,
			SDL_RENDERER_SOFTWARE
			| SDL_RENDERER_PRESENTVSYNC)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (ren);
}

static struct SDL_Renderer		*h_on_v_off(SDL_Window *win,
							struct SDL_Renderer *ren)
{
	if (!(ren = SDL_CreateRenderer(
			win,
			-1,
			SDL_RENDERER_ACCELERATED)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (ren);
}

static struct SDL_Renderer		*h_on_v_on(SDL_Window *win,
							struct SDL_Renderer *ren)
{
	if (!(ren = SDL_CreateRenderer(
			win,
			-1,
			SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	return (ren);
}

struct SDL_Renderer				*ft_init_renderer(SDL_Window *win, t_sdl *sdl)
{
	SDL_Renderer 				*ren;
	ren = NULL;
	if (sdl->hard_accel == 0 && sdl->vsync == 0)
		ren = h_off_v_off(win, ren);
	if (sdl->hard_accel == 0 && sdl->vsync == 1)
		ren = h_off_v_on(win, ren);
	if (sdl->hard_accel == 1 && sdl->vsync == 0)
		ren = h_on_v_off(win, ren);
	if (sdl->hard_accel == 1 && sdl->vsync == 1)
		ren = h_on_v_on(win, ren);
	if (ren == NULL)
		ft_error(INIT_REN);
	return (ren);
}
