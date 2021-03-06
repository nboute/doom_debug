/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_menu_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:24:27 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 17:04:20 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_play_op(t_env *env)
{
	if (env->play_menu == 1)
	{
		switch_play_1(env);
		switch_play_2(env);
		switch_play_3(env);
		switch_play_4(env);
		switch_play_5(env);
		switch_play_6(env);
		open_story(env);
		open_arcade(env);
		open_multi(env);
		exit_from_play_menu(env);
	}
}

void	play_menu(t_env *env)
{
	if (env->play_menu == 1)
	{
		if (env->play_story == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(PLAY_STORY)))
				ft_sdl_error(NULL);
		}
		else if (env->play_arcade == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(PLAY_ARCADE)))
				ft_sdl_error(NULL);
		}
		else if (env->play_multi == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(PLAY_MULTI)))
				ft_sdl_error(NULL);
		}
		else if (env->play_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(PLAY_RETURN)))
				ft_sdl_error(NULL);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			ft_sdl_error("play_menu 2/n");
		if (env->texte)
			ft_free_surface(&env->texte);
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
			ft_free_texture(&env->fontTex);
	}
}