/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:44:46 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 17:38:16 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

SDL_Surface			*ft_load_texture(char *file)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;

	if (!(stock = SDL_LoadBMP(file)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (!(surface = SDL_ConvertSurfaceFormat(stock, SDL_PIXELFORMAT_RGBA8888, 0)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (stock)
		SDL_FreeSurface(stock);
	return (surface);
}

void				ft_init_texture(t_elem *floor)
{
	ft_walltexture(floor);
	ft_floortexture(floor);
	//ft_ceilingtexture(floor);
/*	if (!(floor->weapon = ft_memalloc(sizeof(SDL_Surface) * 7))
{
ft_putendl("malloc failed");
exit(0);
}
	floor->weapon[0] = ft_load_texture("./RSCS/sprite/shotgun0.bmp");
	floor->weapon[1] = ft_load_texture("./RSCS/sprite/shotgun1.bmp");
	floor->weapon[2] = ft_load_texture("./RSCS/sprite/shotgun2.bmp");
	floor->weapon[3] = ft_load_texture("./RSCS/sprite/shotgun3.bmp");
	floor->weapon[4] = ft_load_texture("./RSCS/sprite/shotgun4.bmp");
	floor->weapon[5] = ft_load_texture("./RSCS/sprite/shotgun5.bmp");*/
	//floor->floor_texture = ft_load_texture(TEXT_FLOOR);
	//floor->skybox = ft_load_texture("./RSCS/skybox/skybox.bmp");
}
