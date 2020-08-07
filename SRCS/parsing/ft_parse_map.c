/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:47:06 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 16:51:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static int				ft_parsemapret(t_elem *floor)
{
	if (ft_filwidth(floor) == 1)
		return (ft_error(6));
	if (ft_checkspawn(floor) == 1)
		return (ft_error(7));
	if (ft_wolfcheck(floor) == 1)
		return (ft_error(8));
	if (ft_checkvalue(floor) == 1)
		return (ft_error(8));
	if (ft_checkstairs(floor) == 1)
		return (ft_error(6));
	if (ft_checkmap(floor) == 1)
		return (ft_error(6));
	else
		return (0);
}

static void				ft_create_floors_malloc(t_elem *floor, int i)
{
	int			j;

	j = 0;
	floor[i].map = (char ***)ft_memalloc(sizeof(char **) * 1000);
	j = 0;
	while (floor[i].box[j])
	{
		floor[i].map[j] = ft_strsplit(floor[i].box[j], ' ');
		j++;
	}
}

static t_elem			*ft_create_floors(t_map *map)
{
	t_elem		*floor;
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(map->tmp, '|');
	while (tab[i] != NULL)
		i++;
	floor = (t_elem *)ft_memalloc(sizeof(t_elem) * i);
	floor->max_floor = i;
	i = -1;
	while (++i < floor->max_floor)
		floor[i].box = ft_strsplit(tab[i], '\n');
	i = -1;
	while (++i < floor->max_floor)
		ft_create_floors_malloc(floor, i);
	ft_memdel((void **)&map->line);
	ft_memdel((void **)&map->tmp);
	ft_freetab(&tab);
	return (floor);
}

int						ft_parse_map_param(t_map *map)
{
	t_elem		*floor;
	int			ret;

	ret = 0;
	map->fd = (open(map->file, O_RDONLY));
	if (map->fd == -1)
		return (1);
	map->tmp = ft_strnew(0);
	while (get_next_line(map->fd, &map->line))
	{
		map->tmp = join_free(map->tmp, map->line);
		map->tmp = join_free(map->tmp, "\n");
		ft_strdel(&map->line);
	}
	ft_strdel(&map->line);
	close(map->fd);
	floor = ft_create_floors(map);
	ret = ft_parsemapret(floor);
	ft_newmap(floor);
	map->floor = floor;
	ft_printmap(map->floor);
	if (ret != 0)
		return (1);
	return (0);
}
