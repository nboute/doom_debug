/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:08:24 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 16:54:37 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int		ft_exit_sdl(t_env *env)
{
	if (env->police2)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	if (env->police)
		TTF_CloseFont(env->police);
	env->police = NULL;
	if (env->ren)
		SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	if (env->win)
		SDL_DestroyWindow(env->win);
	env->win = NULL;
	TTF_Quit();
	SDL_Quit();
	return (1);
}

void	ft_sdl_error(char *str)
{
	ft_putendl(SDL_GetError());
	if (str)
		ft_putendl(str);
	exit(0);
}

void	ft_ttf_error(char *str)
{
	ft_putendl(TTF_GetError());
	if (str)
		ft_putendl(str);
	exit(0);
}

void	ft_free_surface(SDL_Surface **surface)
{
	if (!surface)
		return ;
	if (*surface)
		SDL_FreeSurface(*surface);
	*surface = NULL;
}

void	ft_free_texture(SDL_Texture **texture)
{
	if (!texture)
		return ;
	if (*texture)
		SDL_DestroyTexture(*texture);
	*texture = NULL;
}
