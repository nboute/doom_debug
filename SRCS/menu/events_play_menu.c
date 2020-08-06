/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_play_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:29:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 18:29:05 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_play_menu(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && 
		(env->events.type == SDL_KEYDOWN) && (env->play_return == 1))
	{
		env->play_menu = 0;
		env->play_return = 0;
		env->menu = 1;
		env->play = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->events.type == SDL_MOUSEBUTTONDOWN) && (env->play_return == 1))
	{
		env->play_menu = 0;
		env->play_return = 0;
		env->menu = 1;
		env->play = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_story(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN)
			&& (env->events.type == SDL_KEYDOWN) && (env->play_story == 1))
	{
		env->play_menu = 0;
		env->play_story = 0;
		env->story_menu = 1;
		env->story_normal = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->play_story == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->play_menu = 0;
		env->play_story = 0;
		env->story_menu = 1;
		env->story_normal = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_arcade(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN)
			&& (env->events.type == SDL_KEYDOWN) && (env->play_arcade == 1))
	{
		env->play_menu = 0;
		env->play_arcade = 0;
		env->arcade_menu = 1;
		env->arcade_map = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->play_arcade == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->play_menu = 0;
		env->play_arcade = 0;
		env->arcade_menu = 1;
		env->arcade_map = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_multi(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN)
			&& (env->events.type == SDL_KEYDOWN) && (env->play_multi == 1))
	{
		env->play_menu = 0;
		env->play_multi = 0;
		env->multi_menu = 1;
		env->multi_map = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->play_multi == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->play_menu = 0;
		env->play_multi = 0;
		env->multi_menu = 1;
		env->multi_map = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}