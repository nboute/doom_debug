/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ttf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:35:10 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/05 19:34:06 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	set_ttf(t_env *env)
{
	if (!(env->police2 = TTF_OpenFont("./RSCS/fonts/wolfenstein.ttf", 60)))
{
ft_putendl(TTF_GetError());
exit(0);
}
	env->red.r = 165;
	env->red.g = 25;
	env->red.b = 25;
	env->red.a = 0;
}

void	set_ttf_rect(t_env *env, double x, double y, double w, double h)
{
	env->pos2.x = x;
	env->pos2.y = y;
	env->pos2.w = w;
	env->pos2.h = h;
}
