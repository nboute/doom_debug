/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:11:42 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 08:13:10 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void	ft_floor_textnum(t_elem *floor)
{
	if ((!(floor[0].new[(int)floor->mapy][(int)floor->mapx][FLOOR_TXT]))
		|| ft_ctoi(&floor[0].new[(int)floor->mapy]
			[(int)floor->mapx][FLOOR_TXT]) > 3)
		floor->floor_txtnum = 0;
	else
		floor->floor_txtnum =
	ft_ctoi(&floor[0].new[(int)floor->mapy][(int)floor->mapx][FLOOR_TXT]);
}

static	void	ft_ceiling_textnum(t_elem *floor)
{
	if ((!(floor[0].new[(int)floor->mapy][(int)floor->mapx][CEILING_TXT]))
		|| ft_ctoi(&floor[0].new[(int)floor->mapy]
			[(int)floor->mapx][CEILING_TXT]) > 3)
		floor->ceiling_txtnum = 0;
	else
		floor->ceiling_txtnum =
	ft_ctoi(&floor[0].new[(int)floor->mapy][(int)floor->mapx][CEILING_TXT]);
}

static	void	ft_wall_textnum(t_elem *floor)
{
	if (!(floor[0].new[(int)floor->mapy][(int)floor->mapx][WALL_TEXT]))
		floor->txtnum = 0;
	else
		floor->txtnum = ft_ctoi(&floor[0].new[(int)floor->mapy]
			[(int)floor->mapx][WALL_TEXT]);
}

void			ft_texnum(t_elem *floor)
{
	ft_wall_textnum(floor);
	ft_ceiling_textnum(floor);
	ft_floor_textnum(floor);
}
