/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_video_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:34:57 by jcharrou          #+#    #+#             */
/*   Updated: 2020/01/15 16:32:45 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_video_op_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->res == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->res = 0;
		env->vsync = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->vsync == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->vsync = 0;
		env->fullscreen = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s)
			&& (env->fullscreen == 1) && (env->events.type == SDL_KEYDOWN))
	{
		env->fullscreen = 0;
		env->gpu = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_video_op_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->res == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->ret_op = 1;
		env->res = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->ret_op == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->ret_op = 0;
		env->apply = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->apply = 0;
		env->text_q = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_video_op_3(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->fullscreen == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->vsync = 1;
		env->fullscreen = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->vsync == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->vsync = 0;
		env->res = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->apply = 0;
		env->ret_op = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_video_op_4(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->gpu == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->gpu = 0;
		env->aliasing = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->text_q == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->apply = 1;
		env->text_q = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->gpu == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->fullscreen = 1;
		env->gpu = 0;
		env->events.type = SDL_KEYUP;
	}
}
