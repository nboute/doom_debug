/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speedshift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:11:54 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/15 17:11:57 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_speedshift(t_env *env, t_elem *floor)
{
	if ((env->events.key.keysym.sym == SDLK_LSHIFT)
		&& (env->events.type == SDL_KEYUP))
		floor->speedshift = 0.5;
	if ((env->events.key.keysym.sym == SDLK_LSHIFT)
		&& (env->events.type == SDL_KEYDOWN))
		floor->speedshift = 1.0;
}
