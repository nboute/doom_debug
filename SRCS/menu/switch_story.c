/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_story.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:34:54 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 18:34:57 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_story_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->story_normal == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_normal = 0;
		env->story_hard = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->story_hard == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_hell = 1;
		env->story_hard = 0;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->story_hell == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_hell = 0;
		env->story_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->story_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_return = 0;
		env->story_normal = 1;
	}
}

void	switch_story_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->story_normal == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_normal = 0;
		env->story_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->story_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_return = 0;
		env->story_hell = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->story_hell == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_hell = 0;
		env->story_hard = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->story_hard == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_hard = 0;
		env->story_normal = 1;
	}
}

void	switch_story_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > env->res_hight / 3) 
					&& (env->cursy < (env->res_hight / 3) * 1.4))
		{
			env->story_normal = 1;
			env->story_hard = 0;
			env->story_hell = 0;
			env->story_return = 0;
		}
	}
}
