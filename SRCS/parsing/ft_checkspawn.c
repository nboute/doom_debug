/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:15:49 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/10 01:15:50 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_checkspawninit(t_elem *floor, int i, int j, int k)
{
	if (floor[i].map[j][k][0] == '#')
	{
		floor->spawn_x = k + 1.5;
		floor->spawn_y = j + 1.5;
		floor->spawn_floor = i;
		floor->spawn++;
	}
}

int				ft_checkspawn(t_elem *floor)
{
	int i;
	int j;
	int k;

	i = -1;
	floor->spawn = 0;
	while (++i < floor->max_floor)
	{
		j = -1;
		while (floor[i].map[++j])
		{
			k = -1;
			while (floor[i].map[j][++k])
				ft_checkspawninit(floor, i, j, k);
		}
	}
	if (floor->spawn != 1)
		return (1);
	return (0);
}
