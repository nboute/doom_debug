/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:36:03 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 17:23:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_initfps(t_elem *floor, t_env *env)
{
	env->rectfps.x = env->res_width / 1.1;
	env->rectfps.y = env->res_hight / 20;
	env->rectfps.w = env->res_width / 15;
	env->rectfps.h = env->res_hight / 12;
	if (!(floor->fpsfont = TTF_OpenFont("./RSCS/fonts/wolfenstein.ttf", 60)))
	{
		ft_putendl(TTF_GetError());
		exit(0);
	}
	floor->fpscolor.r = 165;
	floor->fpscolor.g = 25;
	floor->fpscolor.b = 25;
	floor->fpscolor.a = 0;
}

void		ft_countfps(t_elem *floor)
{
	floor->oldtime = floor->time;
	floor->time = SDL_GetTicks();
	floor->frametime = (floor->time - floor->oldtime) / 1000.0;
}

Uint32		ft_printfps(Uint32 intervalle, void *parametre)
{
	t_elem *floor;

	floor = parametre;
	if (floor->fps)
		ft_strdel(&floor->fps);
	floor->fps = ftoa(1.0 / floor->frametime, floor->fps);
	return (intervalle);
}
