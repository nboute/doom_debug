/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walltexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:29:23 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 08:42:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void			ft_walltextureepic(t_elem *floor)
{
	floor->walltext[0] = ft_load_texture(WAL_EPIC_0);
	floor->walltext[1] = ft_load_texture(WAL_EPIC_1);
	floor->walltext[2] = ft_load_texture(WAL_EPIC_2);
	floor->walltext[3] = ft_load_texture(WAL_EPIC_3);
	floor->walltext[4] = ft_load_texture(WAL_EPIC_4);
	floor->walltext[5] = ft_load_texture(WAL_EPIC_5);
	floor->walltext[6] = ft_load_texture(WAL_EPIC_6);
	floor->walltext[7] = ft_load_texture(WAL_EPIC_7);
	floor->walltext[8] = ft_load_texture(WAL_EPIC_8);
	floor->walltext[9] = ft_load_texture(WAL_EPIC_9);
}

static	void			ft_walltexturehigh(t_elem *floor)
{
	floor->walltext[0] = ft_load_texture(WAL_HIGH_0);
	floor->walltext[1] = ft_load_texture(WAL_HIGH_1);
	floor->walltext[2] = ft_load_texture(WAL_HIGH_2);
	floor->walltext[3] = ft_load_texture(WAL_HIGH_3);
	floor->walltext[4] = ft_load_texture(WAL_HIGH_4);
	floor->walltext[5] = ft_load_texture(WAL_HIGH_5);
	floor->walltext[6] = ft_load_texture(WAL_HIGH_6);
	floor->walltext[7] = ft_load_texture(WAL_HIGH_7);
	floor->walltext[8] = ft_load_texture(WAL_HIGH_8);
	floor->walltext[9] = ft_load_texture(WAL_HIGH_9);
}

static	void			ft_walltexturenormal(t_elem *floor)
{
	floor->walltext[0] = ft_load_texture(WAL_NORMAL_0);
	floor->walltext[1] = ft_load_texture(WAL_NORMAL_1);
	floor->walltext[2] = ft_load_texture(WAL_NORMAL_2);
	floor->walltext[3] = ft_load_texture(WAL_NORMAL_3);
	floor->walltext[4] = ft_load_texture(WAL_NORMAL_4);
	floor->walltext[5] = ft_load_texture(WAL_NORMAL_5);
	floor->walltext[6] = ft_load_texture(WAL_NORMAL_6);
	floor->walltext[7] = ft_load_texture(WAL_NORMAL_7);
	floor->walltext[8] = ft_load_texture(WAL_NORMAL_8);
	floor->walltext[9] = ft_load_texture(WAL_NORMAL_9);
}

void					ft_walltexture(t_elem *floor)
{
	if (floor->walltext)
		ft_free_surface_tab(&floor->walltext);
	if (!(floor->walltext = ft_memalloc(sizeof(SDL_Surface*) * 11)))
	{
		ft_fct_error("malloc failed");
	}
	if (floor->texture_res == 1)
		ft_walltexturenormal(floor);
	else if (floor->texture_res == 2)
		ft_walltexturehigh(floor);
	else if (floor->texture_res == 3)
		ft_walltextureepic(floor);
}
