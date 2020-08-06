/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:39 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 03:47:40 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_initcolors(t_env *env, t_elem *floor)
{
	floor->red = SDL_MapRGBA(env->surf->format, 255, 0, 0, 255);
	floor->green = SDL_MapRGBA(env->surf->format, 0, 255, 0, 255);
	floor->blue = SDL_MapRGBA(env->surf->format, 0, 0, 255, 255);
	floor->grey = SDL_MapRGBA(env->surf->format, 0xC0, 0xC0, 0xC0, 255);
	floor->black = SDL_MapRGBA(env->surf->format, 0, 0, 0, 255);
	floor->white = SDL_MapRGBA(env->surf->format, 255, 255, 255, 255);
}

static void		ft_initraycasting_2(t_elem *floor)
{
	floor->m = 0;
	floor->playerwidth = 0.8;
	floor->crouchsensi = 1;
	floor->flysensi = 1;
	floor->psyeffect = 0;
	floor->psy = 0;
	floor->crouch = 0;
	floor->fly = 0;
	floor->deltacrouch = 0;
	floor->deltafly = 0;
	floor->walk = 0;
	floor->swim = 0;
	floor->jump = 0;
	floor->gravity = 1;
	floor->walkswitch = 0;
}

void			ft_initraycasting(t_elem *floor)
{
	floor->texture_res = 1;
	floor->speed = 0.03;
	floor->sensitivity_x = 5;
	floor->sensitivity_y = 1;
	floor->sensitivity_setup = 1;
	floor->angle = M_PI;
	floor->rotatespeed = 0.02;
	floor->posx = floor->spawn_x;
	floor->posy = floor->spawn_y;
	floor->time = 0;
	floor->oldtime = 0;
	floor->speedshift = 0.5;
	floor->fps = NULL;
	floor->lookupdown = 0;
	floor->newlookupdown = 0;
	ft_initraycasting_2(floor);
}
