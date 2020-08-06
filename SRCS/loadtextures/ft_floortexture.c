/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floortexture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:29:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 17:29:43 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void			ft_floortextureepic(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_EPIC_0);
	floor->floortext[1] = ft_load_texture(FLO_EPIC_1);
	floor->floortext[2] = ft_load_texture(FLO_EPIC_2);
}

static	void			ft_floortexturehigh(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_HIGH_0);
	floor->floortext[1] = ft_load_texture(FLO_HIGH_1);
	floor->floortext[2] = ft_load_texture(FLO_HIGH_2);

}

static	void			ft_floortexturenormal(t_elem *floor)
{
	floor->floortext[0] = ft_load_texture(FLO_NORMAL_0);
	floor->floortext[1] = ft_load_texture(FLO_NORMAL_1);
	floor->floortext[2] = ft_load_texture(FLO_NORMAL_2);
}

void			ft_floortexture(t_elem *floor)
{
	if (!(floor->floortext = ft_memalloc(sizeof(SDL_Surface) * 4)))
	{
		ft_putendl("malloc failed");
		exit(0);
	}
	if (floor->texture_res == 1)
		ft_floortexturenormal(floor);
	if (floor->texture_res == 2)
		ft_floortexturehigh(floor);
	if (floor->texture_res == 3)
		ft_floortextureepic(floor);
}
