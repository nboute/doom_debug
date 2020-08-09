/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arcade_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:11:38 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 19:05:46 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_arcade(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && 
		(env->events.type == SDL_KEYDOWN) && (env->arcade_return == 1))
	{
		env->arcade_menu = 0;
		env->arcade_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->events.type == SDL_MOUSEBUTTONDOWN) && (env->arcade_return == 1))
	{
		env->arcade_menu = 0;
		env->arcade_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	arcade_menu(t_env *env)
{
	if (env->arcade_menu == 1)
	{
		if (env->arcade_map == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(ARCADE_MAP)))
				ft_sdl_error("arcade_map");
		}
		else if (env->arcade_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(ARCADE_RETURN)))
				ft_sdl_error("arcade_return");
		}
		if (env->texte == NULL)
			ft_sdl_error("arcade_menu");
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			ft_sdl_error(NULL);
		ft_free_surface(&env->texte);
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		ft_free_texture(&env->fontTex);
	}
}
