/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:28:26 by jcharrou          #+#    #+#             */
/*   Updated: 2020/01/15 16:24:10 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_option(t_env *env)
{
	if (env->op_menu == 1)
	{
		switch_option_1(env);
		switch_option_2(env);
		switch_option_3(env);
	}
}

void	open_video(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->video == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->op_menu == 1))
	{
		env->op_menu = 0;
		env->video = 0;
		env->vid_menu = 1;
		env->ret_op = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->video == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->op_menu == 1))
	{
		env->op_menu = 0;
		env->video = 0;
		env->vid_menu = 1;
		env->ret_op = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_gameplay(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->gameplay == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->op_menu == 1))
	{
		env->op_menu = 0;
		env->video = 0;
		env->gameplay_menu = 1;
		env->game_difficulty = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->op_menu == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->gameplay == 1))
	{
		env->op_menu = 0;
		env->video = 0;
		env->gameplay_menu = 1;
		env->game_difficulty = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	open_audio(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->audio == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->op_menu == 1))
	{
		env->op_menu = 0;
		env->audio = 0;
		env->audio_menu = 1;
		env->audio_volume = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->op_menu == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->audio == 1))
	{
		env->op_menu = 0;
		env->audio = 0;
		env->audio_menu = 1;
		env->audio_volume = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}



void	exit_from_option(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->ex_opt == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->op_menu == 1))
	{
		env->ex_opt = 0;
		env->op_menu = 0;
		env->menu = 1;
		env->play = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->ex_opt == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->op_menu == 1))
	{
		env->ex_opt = 0;
		env->op_menu = 0;
		env->menu = 1;
		env->play = 1;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}
