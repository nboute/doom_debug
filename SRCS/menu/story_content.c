/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:43:48 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/05 20:47:43 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_story_op(t_env *env)
{
	if (env->story_menu == 1)
	{
		switch_story_1(env);
		switch_story_2(env);
		switch_story_3(env);
		switch_story_4(env);
		switch_story_5(env);
		switch_story_6(env);
		open_normal(env);
		open_hard(env);
		open_hell(env);
		exit_from_story(env);
	}
}

void	story_menu(t_env *env)
{
	if (env->story_menu == 1)
	{
		if (env->story_normal == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(STORY_NORMAL)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->story_hard == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(STORY_HARD)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->story_hell == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(STORY_HELL)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->story_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(STORY_RETURN)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		if (env->texte < 0)
		{
			ft_putendl("story_menu 1/n");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		{
			ft_putendl("story_menu 2/n");
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