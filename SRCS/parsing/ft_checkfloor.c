/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfloor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:42:03 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 00:47:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			ft_filmap(t_elem *floor)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < floor->max_floor)
	{
		j = 0;
		while (floor[i].map[j])
		{
			k = 0;
			while (floor[i].map[j][k])
			{
				ft_strcpy(floor[i].new[j + 1][k + 1], floor[i].map[j][k]);
				k++;
			}
			j++;
		}
		i++;
	}
}

static	void	ft_newmapmalloc(t_elem *floor, int i, int j, int k)
{
	size_t	len;

	if (j < floor[i].nh && k < floor[i].nw)
	{
		len = ft_strlen(floor[i].map[j][k]) + 1;
		floor[i].new[j][k] = (char *)ft_memalloc(sizeof(char)
			* (len < 10 ? 10 : len));
	}
	else
		floor[i].new[j][k] = (char *)ft_memalloc(sizeof(char) * 10);
	ft_strcpy(floor[i].new[j][k], "10000000");
}

static	void	ft_newmapinit(t_elem *floor)
{
	int	i;

	i = -1;
	while (++i < floor->max_floor)
	{
		floor[i].nh = floor[i].hight;
		floor[i].nw = floor[i].width;
		floor[i].hight = floor[i].hight + 2;
		floor[i].width = floor[i].width + 2;
	}
}

void			ft_newmap(t_elem *floor)
{
	int	i;
	int	j;
	int	k;

	ft_newmapinit(floor);
	i = -1;
	while (++i < floor->max_floor)
	{
		floor[i].new =
			(char ***)ft_memalloc(sizeof(char **) * (floor[i].hight + 1));
		j = -1;
		while (++j < floor[i].hight)
		{
			k = -1;
			floor[i].new[j] = (char **)ft_memalloc(sizeof(char *)
				* (floor[i].width + 1));
			while (++k < floor[i].width)
				ft_newmapmalloc(floor, i, j, k);
		}
	}
	ft_filmap(floor);
}
