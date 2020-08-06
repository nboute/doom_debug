/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousemotion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:57:19 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 01:47:00 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_mousemotion(t_env *env, t_elem *floor)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		floor->mousex = env->events.motion.xrel
			/ ((double)floor->sensitivity_x / floor->sensitivity_setup);
		floor->angle -= floor->rotatespeed * floor->mousex;
		floor->newlookupdown += env->events.motion.yrel
		* ((double)floor->sensitivity_y * floor->sensitivity_setup);
		SDL_SetRelativeMouseMode(SDL_TRUE);
		SDL_WarpMouseInWindow(env->win, env->res_width / 2, env->res_hight / 2);
		if (floor->newlookupdown > 600)
			floor->lookupdown = 600;
		else if (floor->newlookupdown < -600)
			floor->lookupdown = -600;
		else
			floor->lookupdown = floor->newlookupdown;
	}
}
