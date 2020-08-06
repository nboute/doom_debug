/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:17:53 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 17:55:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_crouchflyjump(t_env *env, t_elem *floor)
{
	floor->currenttime = SDL_GetTicks();
	if (floor->currenttime - floor->previoustime > 10
		&& env->events.key.repeat == 0 && floor->swim == 0)
	{
		ft_crouch(env, floor);
		ft_fly(env, floor);
		ft_jump(env, floor);
		ft_walk(env, floor);
		floor->previoustime = floor->currenttime;
	}
	floor->previoustime = floor->currenttime;
}

void			ft_movements(t_env *env, t_elem *floor)
{
	ft_mousemotion(env, floor);
	if (env->events.type == SDL_KEYDOWN || env->events.type == SDL_KEYUP)
	{
		ft_dispminimap(env, floor);
		ft_speedshift(env, floor);
		ft_crouchflyjump(env, floor);
	}
}
