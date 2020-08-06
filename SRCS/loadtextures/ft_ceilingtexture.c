/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilingtexture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:29:29 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 17:30:44 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void			ft_ceilingtextureepic(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_EPIC_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_EPIC_1);
	floor->ceilingtext[2] = ft_load_texture(CEL_EPIC_2);
}

static	void			ft_ceilingtexturehigh(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_HIGH_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_HIGH_1);
	floor->ceilingtext[2] = ft_load_texture(CEL_HIGH_2);
}

static	void			ft_ceilingtexturenormal(t_elem *floor)
{
	floor->ceilingtext[0] = ft_load_texture(CEL_NORMAL_0);
	floor->ceilingtext[1] = ft_load_texture(CEL_NORMAL_1);
	floor->ceilingtext[2] = ft_load_texture(CEL_NORMAL_2);
}

void			ft_ceilingtexture(t_elem *floor)
{
	if (!(floor->ceilingtext = ft_memalloc(sizeof(SDL_Surface) * 4)))
{
ft_putendl("malloc failed");
exit(0);
}
	if (floor->texture_res == 1)
		ft_ceilingtexturenormal(floor);
	if (floor->texture_res == 2)
		ft_ceilingtexturehigh(floor);
	if (floor->texture_res == 3)
		ft_ceilingtextureepic(floor);
}
