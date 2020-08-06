/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:03:26 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/05 03:34:17 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static Uint32		ft_flydown(Uint32 intervalle, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi >= 1)
		floor->flysensi = floor->flysensi - 0.05;
	else if (floor->flysensi <= 1)
	{
		SDL_RemoveTimer(floor->timerflydown);
		floor->fly = 0;
	}
	return (intervalle);
}

static Uint32		ft_flyup(Uint32 intervalle, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi <= 4)
		floor->flysensi = floor->flysensi + 0.05;
	else if (floor->flysensi >= 4)
	{
		SDL_RemoveTimer(floor->timerflyup);
		floor->fly = 1;
	}
	return (intervalle);
}

void				ft_fly(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_f
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 0 && floor->crouch == 0)
	{
		if (!(floor->timerflyup = SDL_AddTimer(10 * floor->gravity, ft_flyup,
			floor)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		floor->speed = 0.01;
		floor->previoustime = floor->currenttime;
	}
	if (env->events.key.keysym.sym == SDLK_f
		&& env->events.type == SDL_KEYDOWN
		&& floor->fly == 1)
	{
		if (!(floor->timerflydown = SDL_AddTimer(10
			* floor->gravity, ft_flydown, floor)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		floor->speed = 0.03;
		floor->previoustime = floor->currenttime;
	}
}
