/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:01:28 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 00:10:54 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_control(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->show_controls == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->show_controls = 0;
		env->gameplay_menu = 1;
		env->game_controls = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->show_controls == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->show_controls = 0;
		env->gameplay_menu = 1;
		env->game_controls = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	control_menu(t_env *env)
{
	if (env->show_controls == 1)
	{
		if (!(env->texte  = SDL_LoadBMP(SHOW_CONTROLS)))
		{
			ft_putendl("control_menu 1");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		{
			ft_putendl("control_menu 2");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (env->texte)
		{
			SDL_FreeSurface(env->texte);
			env->texte = NULL;
		}
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
		{
			SDL_DestroyTexture(env->fontTex);
			env->fontTex = NULL;
		}
	}
}
