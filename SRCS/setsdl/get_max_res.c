/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:38:30 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:06:38 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	get_max_res(t_sdl *sdl)
{
	SDL_DisplayMode		current;
	int					display;

	display = SDL_GetCurrentDisplayMode(0, &current);
	sdl->w_max = current.w;
	sdl->h_max = current.h;
}
