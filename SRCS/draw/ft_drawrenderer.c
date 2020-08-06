/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrenderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:28 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 03:44:29 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_drawrenderer(t_env *env, t_elem *floor)
{
	//drawskybox
	//ft_draw_floor(env, floor);
	//ft_draw_top(env, floor);
	ft_raycasting(env, floor);
	if (floor->m == 1)
		ft_minimap(env, floor);
	ft_radar(env, floor);
}
