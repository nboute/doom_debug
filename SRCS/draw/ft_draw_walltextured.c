/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolftext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:43:51 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 17:43:52 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_draw_walltextured(t_env *env, t_elem *floor)
{
	floor->wallx = floor->side == 0 ? (floor->wallx = floor->rposy
		+ floor->perwalldist * floor->rdiry) : (floor->wallx = floor->rposx
		+ floor->perwalldist * floor->rdirx);
	floor->wallx -= ft_floor((floor->wallx));
	floor->texx = (int)(floor->wallx * (double)TEXT_W);
	if (floor->side == 0 && floor->rdirx > 0)
		floor->texx = TEXT_W - floor->texx - 1;
	if (floor->side == 1 && floor->rdiry < 0)
		floor->texx = TEXT_W - floor->texx - 1;
	floor->step = 1.0 * TEXT_H / floor->linehight;
	floor->texpos = ((floor->dst + floor->lookupdown
		- env->res_hight / 2 + floor->linehight / 2) - floor->deltaline) * floor->step;
	while (++floor->y < floor->dend)
	{
		floor->texy = (int)floor->texpos & (TEXT_H - 1);
		floor->texpos += floor->step;
		floor->color = ft_readpixel(floor->walltext[floor->txtnum],
			floor->texx, floor->texy);
		ft_putpixel(env->surf, floor->x, floor->y, floor->color);
	}
}
