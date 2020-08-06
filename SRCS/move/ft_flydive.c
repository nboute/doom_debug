/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flydive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:17:53 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/29 16:17:55 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_dive(t_elem *floor)
{
	if (floor->swim == 1)
	{
		floor->speed = 0.01;
		if (floor->keystat[SDL_SCANCODE_V] && floor->flysensi < 4
			&& floor->crouchsensi <= 1)
			floor->flysensi = floor->flysensi + 0.02;
		if (floor->keystat[SDL_SCANCODE_C] && floor->flysensi > 1)
			floor->flysensi = floor->flysensi - 0.02;
		if (floor->keystat[SDL_SCANCODE_C] && floor->flysensi == 1
			&& floor->crouchsensi <= 4)
			floor->crouchsensi = floor->crouchsensi + 0.02;
		if (floor->keystat[SDL_SCANCODE_V] && floor->crouchsensi >= 1)
			floor->crouchsensi = floor->crouchsensi - 0.02;
	}
	else if (floor->swim == 0)
		floor->speed = 0.03;
}
