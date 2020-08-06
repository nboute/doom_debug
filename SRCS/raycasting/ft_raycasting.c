/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 03:47:47 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_rayside(t_elem *floor)
{
	if (floor->side == 0)
		floor->perwalldist = fabs((floor->mapx - floor->rposx
			+ (1 - floor->stepx) / 2) / floor->rdirx);
	else
		floor->perwalldist = fabs((floor->mapy - floor->rposy
			+ (1 - floor->stepy) / 2) / floor->rdiry);
}

static	void	ft_setupray(t_env *env, t_elem *floor)
{
	floor->ratio = ((double)floor->x - (double)env->res_width / 2)
		/ (double)(env->res_width / 2);
	floor->rposx = floor->posx;
	floor->rposy = floor->posy;
	floor->mapx = (int)floor->posx;
	floor->mapy = (int)floor->posy;
	floor->rdirx = cos(floor->angle) / 2
		+ cos(floor->angle - 1.5708) * floor->ratio;
	floor->rdiry = sin(floor->angle) / 2
		+ sin(floor->angle - 1.5708) * floor->ratio;
	floor->deltadistx = sqrt(1 + (pow(floor->rdiry, 2) / pow(floor->rdirx, 2)));
	floor->deltadisty = sqrt(1 + (pow(floor->rdirx, 2) / pow(floor->rdiry, 2)));
}

static	void	ft_step(t_elem *floor)
{
	if (floor->rdirx < 0)
	{
		floor->stepx = -1;
		floor->sidedistx = (floor->rposx - floor->mapx) * floor->deltadistx;
	}
	else
	{
		floor->stepx = 1;
		floor->sidedistx = (floor->mapx + 1.0 - floor->rposx)
			* floor->deltadistx;
	}
	if (floor->rdiry < 0)
	{
		floor->stepy = -1;
		floor->sidedisty = (floor->rposy - floor->mapy)
			* floor->deltadisty;
	}
	else
	{
		floor->stepy = 1;
		floor->sidedisty = (floor->mapy + 1.0 - floor->rposy)
			* floor->deltadisty;
	}
}

static	void	ft_hit(t_elem *floor)
{
	floor->hit = 0;
	while (floor->hit == 0)
	{
		if ((floor->sidedistx >= 0 || floor->sidedisty <= 0)
			&& floor->sidedistx < floor->sidedisty)
		{
			floor->sidedistx += floor->deltadistx;
			floor->mapx += floor->stepx;
			floor->side = 0;
		}
		else
		{
			floor->sidedisty += floor->deltadisty;
			floor->mapy += floor->stepy;
			floor->side = 1;
		}
		if (floor[0].new[(int)floor->mapy][(int)floor->mapx][WALL] == '1')
			floor->hit = 1;
		if (!(floor[0].new[(int)floor->mapy][(int)floor->mapx][BLOCK_H]))
			floor->blocksize = 0;
		else
			floor->blocksize =
			ft_ctoi(&floor[0].new[(int)floor->mapy][(int)floor->mapx][BLOCK_H])
				* 100;
	}
}

void			ft_raycasting(t_env *env, t_elem *floor)
{
	floor->x = -1;
	while (++floor->x < env->res_width)
	{
		ft_setupray(env, floor);
		ft_step(floor);
		ft_hit(floor);
		ft_rayside(floor);
		ft_drawfloorceiling(env, floor);
		if (floor->psy == 1)
			floor->psyeffect = env->res_hight / 8;
		floor->crouchds = floor->linehight / (2 * floor->flysensi);
		floor->crouchde = floor->linehight / (2 * floor->crouchsensi);
		floor->deltaline = floor->crouchde - floor->crouchds;
		floor->deltacrouch = floor->deltaline >= 0 ? 0 : floor->deltaline;
		floor->deltafly = floor->deltaline <= 0 ? 0 : floor->deltaline;
		floor->linehight = abs((int)(env->res_hight / floor->perwalldist));
		floor->dst = (-floor->linehight / (2 * floor->flysensi) + env->res_hight / 2
			- floor->lookupdown - floor->blocksize) + floor->deltacrouch;
		floor->dst = floor->dst < 0 ? 0 : floor->dst;
		floor->dend = (floor->linehight / (2 * floor->crouchsensi) + env->res_hight / 2
			- floor->lookupdown - floor->psyeffect) + floor->deltafly;
		floor->dend =
			floor->dend > env->res_hight ? env->res_hight : floor->dend;
		floor->y = floor->dst - floor->psyeffect;
		floor->y = floor->y < 0 ? 0 : floor->y;
		floor->y = floor->y > env->res_hight ? env->res_hight : floor->y;
		ft_texnum(floor);
		ft_draw_walltextured(env, floor);
	}
}
