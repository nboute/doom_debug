/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawcompass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:09:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 07:55:48 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_drawcompass(int x, int y, t_env *env, t_elem *floor)
{
	floor->cray = 0;
	floor->cmpr = 30;
	while (floor->cray < 10)
	{
		floor->cmppixel0.x = x;
		floor->cmppixel0.y = y;
		floor->cmppixel1.x = floor->cmppixel0.x - cos(floor->angle)
			* floor->cmpr + floor->cray;
		floor->cmppixel1.y = floor->cmppixel0.y + sin(floor->angle)
			* floor->cmpr;
		ft_bresenham(env->surf, floor->cmppixel0, floor->cmppixel1, floor->red);
		floor->cray++;
	}
}
