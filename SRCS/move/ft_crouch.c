/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crouch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:20 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/05 03:34:54 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static Uint32		ft_crouchup(Uint32 intervalle, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi >= 1)
		floor->crouchsensi = floor->crouchsensi - 0.05;
	else if (floor->crouchsensi <= 1)
	{
		SDL_RemoveTimer(floor->timercrouchup);
		floor->crouch = 0;
	}
	return (intervalle);
}

static Uint32		ft_crouchdown(Uint32 intervalle, void *param)
{
	t_elem	*floor;

	floor = param;
	if (floor->crouchsensi <= 4)
		floor->crouchsensi = floor->crouchsensi + 0.05;
	else if (floor->crouchsensi >= 4)
	{
		SDL_RemoveTimer(floor->timercrouchdown);
		floor->crouch = 1;
	}
	return (intervalle);
}

void				ft_crouch(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_LCTRL
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 0 && floor->crouch == 0)
	{
		if (!(floor->timercrouchdown = SDL_AddTimer(10
			* floor->gravity, ft_crouchdown, floor)))
		{
		ft_putendl(SDL_GetError());
		exit(0);
		}
		floor->speed = 0.01;
		floor->previoustime = floor->currenttime;
	}
	if (env->events.key.keysym.sym == SDLK_LCTRL
		&& env->events.type == SDL_KEYDOWN
		&& floor->crouch == 1)
	{
		if (!(floor->timercrouchup = SDL_AddTimer(10
			* floor->gravity, ft_crouchup, floor)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		floor->speed = 0.03;
		floor->previoustime = floor->currenttime;
	}
}
