/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:08:24 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/05 20:46:44 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int		ft_exit_SDL(t_env *env)
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
	SDL_Quit();
	return (1);
}

void	ft_sdl_error()
{
	ft_putendl(SDL_GetError());
	exit(0);
}

void	ft_free_surface_texte(t_env *env)
{
	SDL_FreeSurface(env->texte);
	env->texte = NULL;
}

void	ft_free_texture_fontex(t_env *env)
{
	SDL_DestroyTexture(env->fontTex);
	env->fontTex = NULL;
}
