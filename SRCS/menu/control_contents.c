/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:01:28 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 17:03:51 by niboute          ###   ########.fr       */
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
			ft_sdl_error(NULL);
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			ft_sdl_error("control_menu 2");
		if (env->texte)
			ft_free_surface(&env->texte);
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
			ft_free_texture(&env->fontTex);
	}
}
