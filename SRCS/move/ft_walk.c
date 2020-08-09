/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:07:51 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 08:36:36 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static Uint32	ft_walkint(Uint32 intervalle, void *param)
{
	t_elem *floor;

	floor = param;
	if (floor->flysensi <= 1.1 && floor->jump == 0)
		floor->flysensi = floor->flysensi + 0.05;
	else if (floor->flysensi >= 1.1)
		floor->jump = 1;
	if (floor->flysensi >= 1 && floor->jump == 1)
		floor->flysensi = floor->flysensi - 0.05;
	if (floor->jump == 1 && floor->flysensi <= 1)
		SDL_RemoveTimer(floor->timerwalk);
	return (intervalle);
}

void			ft_walk(t_env *env, t_elem *floor)
{
	if (env->events.key.keysym.sym == SDLK_w
		&& env->events.key.repeat == 1
		&& env->events.type == SDL_KEYDOWN
		&& floor->flysensi == 1)
	{
		if (!(floor->timerwalk = SDL_AddTimer(10
			* floor->gravity, ft_walkint, floor)))
		{
			ft_sdl_error(NULL);
		}
		floor->previoustime = floor->currenttime;
	}
}
