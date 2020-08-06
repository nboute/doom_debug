/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:28:07 by jcharrou          #+#    #+#             */
/*   Updated: 2020/01/15 16:17:24 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_menu(t_env *env)
{
	if (env->menu == 1)
	{
		switch_menu_1(env);
		switch_menu_2(env);
		switch_menu_3(env);
	}
}

void	open_options(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->option == 1)
		&& (env->events.type == SDL_KEYDOWN) && (env->menu == 1))
	{
		env->menu = 0;
		env->option = 0;
		env->op_menu = 1;
		env->video = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->option == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->menu == 1))
	{
		env->menu = 0;
		env->option = 0;
		env->op_menu = 1;
		env->video = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	open_play_content(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->play == 1)
		&& (env->events.type == SDL_KEYDOWN) && (env->menu == 1))
	{
		env->menu = 0;
		env->play = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->play == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->menu == 1))
	{
		env->menu = 0;
		env->play = 0;
		env->play_menu = 1;
		env->play_story = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	play_option(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->play == 1)
		&& (env->events.type == SDL_KEYDOWN) && (env->menu == 1))
	{
		env->menu = 0;
		env->play = 0;
		env->play_ready = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->play == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->menu == 1))
	{
		env->menu = 0;
		env->play = 0;
		env->play_ready = 1;
	}
}

int		exit_from_menu(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->exit == 1)
		&& (env->events.type == SDL_KEYDOWN) && (env->menu == 1))
	{
		return (1);
	}
	else if (env->events.window.event == SDL_WINDOWEVENT_CLOSE)
		return (1);
	else if ((env->events.type == SDL_KEYDOWN) && (env->menu == 1))
	{
		if (env->events.key.keysym.sym == SDLK_ESCAPE)
			return (1);
	}
	if ((env->exit == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->menu == 1))
		return (1);
	return (0);
}
