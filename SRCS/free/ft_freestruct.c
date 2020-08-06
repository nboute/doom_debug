/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 03:45:34 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void					ft_free_tab_telem(t_elem *floor)
{
	int i;

	i = 0;
	while (i < floor->max_floor)
	{
		ft_freetab(floor[i].box);
		ft_freebigtab(floor[i].map);
		ft_freebigtab(floor[i].new);
		i++;
	}
	ft_memdel((void **)floor);
}