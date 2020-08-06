/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_story.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:43:57 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 18:43:59 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_story(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && 
		(env->events.type == SDL_KEYDOWN) && (env->story_return == 1))
	{
		env->story_menu = 0;
		env->story_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->events.type == SDL_MOUSEBUTTONDOWN) && (env->story_return == 1))
	{
		env->story_menu = 0;
		env->story_return = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_normal(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->story_normal == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_menu = 0;
		env->story_normal = 0;
		env->play_ready = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->story_normal == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->story_menu = 0;
		env->story_normal = 0;
		env->play_ready = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_hard(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->story_hard == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_menu = 0;
		env->story_hard = 0;
		env->play_ready = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->story_hard == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->story_menu = 0;
		env->story_hard = 0;
		env->play_ready = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_hell(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->story_hell == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->story_menu = 0;
		env->story_hell = 0;
		env->play_ready = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->story_hell == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->story_menu = 0;
		env->story_hell = 0;
		env->play_ready = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}