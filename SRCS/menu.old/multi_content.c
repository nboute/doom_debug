/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:11:50 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 00:21:53 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_multi(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) &&
		(env->events.type == SDL_KEYDOWN) && (env->multi_return == 1))
	{
		env->multi_menu = 0;
		env->multi_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->events.type == SDL_MOUSEBUTTONDOWN) && (env->multi_return == 1))
	{
		env->multi_menu = 0;
		env->multi_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	multi_menu(t_env *env)
{
	if (env->multi_menu == 1)
	{
		if (env->multi_map == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(MULTI_MAP)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->multi_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(MULTI_RETURN)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		{
			ft_putendl("multi_menu 2/n");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (env->texte)
		{
			SDL_FreeSurface(env->texte);
			SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		}
		if (env->fontTex)
		{
			SDL_DestroyTexture(env->fontTex);
			env->fontTex = NULL;
		}
	}
}

