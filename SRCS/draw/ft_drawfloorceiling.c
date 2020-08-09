/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawfloorceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:28:27 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 07:58:05 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_drawfloorceiling(t_env *env, t_elem *floor)
{
	if (floor->side == 0 && floor->rdirx > 0)
	{
		floor->floorwallx = floor->mapx;
		floor->floorwally = floor->mapy + floor->wallx;
	}
	else if (floor->side == 0 && floor->rdirx < 0)
	{
		floor->floorwallx = floor->mapx + 1.0;
		floor->floorwally = floor->mapy + floor->wallx;
	}
	else if (floor->side == 1 && floor->rdirx > 0)
	{
		floor->floorwallx = floor->mapx + floor->wallx;
		floor->floorwally = floor->mapy;
	}
	else
	{
		floor->floorwallx = floor->mapx + floor->wallx;
		floor->floorwally = floor->mapy + 1.0;
	}
	floor->disttowall = floor->perwalldist;
	floor->playerdist = 0.0;
	if (floor->dend < 0)
		floor->dend = env->res_hight;
	floor->y = floor->dend;
	while (++floor->y < env->res_hight)
	{
		floor->dist = (env->res_hight) / ((2.0 * floor->y - floor->lookupdown)
			- env->res_hight);
		floor->weight = (floor->dist - floor->playerdist) / (floor->disttowall
			- floor->playerdist);
		floor->floorx = floor->weight * floor->floorwallx
			+ (1.0 - floor->weight) * floor->posx;
		floor->floory = floor->weight * floor->floorwally
			+ (1.0 - floor->weight) * floor->posy;
		floor->ftx = (int)(floor->floorx * (double)TEXT_W) & (TEXT_W - 1);
		floor->fty = (int)(floor->floory * (double)TEXT_H) & (TEXT_H - 1);
		floor->floor_txtnum = 0;
		floor->color = ft_readpixel(floor->floortext[floor->floor_txtnum],
			floor->ftx, floor->fty);
		ft_putpixel(env->surf, floor->x, floor->y, floor->color);
		//ft_putpixel(env->surf, floor->x, env->res_hight - floor->y, floor->color);
	}
}
/*
void		texture_floor(t_wolf *wolf)
{
		esdl_put_pixel(wolf->surf, wolf->x, wolf->y, esdl_read_pixel(wolf->floor_texture, wolf->floortexx, wolf->floortexy));
		esdl_put_pixel(wolf->surf, wolf->x, wolf->h - wolf->y, esdl_read_pixel(wolf->ceiling_texture, wolf->floortexx, wolf->floortexy));
}
*/
