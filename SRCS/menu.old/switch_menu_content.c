/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_menu_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:20:32 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 18:20:35 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_play_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->play_story == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_story = 0;
		env->play_arcade = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->play_arcade == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_multi = 1;
		env->play_arcade = 0;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->play_multi == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_multi = 0;
		env->play_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->play_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_return = 0;
		env->play_story = 1;
	}
}

void	switch_play_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->play_story == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_story = 0;
		env->play_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->play_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_return = 0;
		env->play_multi = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->play_multi == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_multi = 0;
		env->play_arcade = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->play_arcade == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play_arcade = 0;
		env->play_story = 1;
	}
}

void	switch_play_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > env->res_hight / 3) 
					&& (env->cursy < (env->res_hight / 3) * 1.4))
		{
			env->play_story = 1;
			env->play_arcade = 0;
			env->play_multi = 0;
			env->play_return = 0;
		}
	}
}
