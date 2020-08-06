/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_video_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:31:24 by jcharrou          #+#    #+#             */
/*   Updated: 2020/01/15 16:29:48 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	back_to_option(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->ret_op == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->ret_op = 0;
		env->vid_menu = 0;
		env->op_menu = 1;
		env->video = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->ret_op == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->ret_op = 0;
		env->vid_menu = 0;
		env->op_menu = 1;
		env->video = 1;
	}
}

void	change_video_option1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->res == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->res_op++;
		if (env->res_op == 3)
			env->res_op = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->res == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->res_op++;
		if (env->res_op == 3)
			env->res_op = 1;
	}
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->vsync == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->vsync_op++;
		if (env->vsync_op == 2)
			env->vsync_op = 0;
		env->events.type = SDL_KEYUP;
	}
}

void	change_video_option2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->fullscreen == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->fs_op++;
		if (env->fs_op == 2)
			env->fs_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->fullscreen == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->fs_op++;
		if (env->fs_op == 2)
			env->fs_op = 0;
	}
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->gpu == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->gpu_op++;
		if (env->gpu_op == 2)
			env->gpu_op = 0;
		env->events.type = SDL_KEYUP;
	}
}

void	change_video_option3(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->aliasing == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->aliasing_op++;
		if (env->aliasing_op == 2)
			env->aliasing_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->aliasing == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->aliasing_op++;
		if (env->aliasing_op == 2)
			env->aliasing_op = 0;
	}
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->text_q == 1)
			&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->text_q_op++;
		if (env->text_q_op == 3)
			env->text_q_op = 0;
		env->events.type = SDL_KEYUP;
	}
}

void	change_video_option4(t_env *env)
{
	if ((env->vsync == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->vsync_op++;
		if (env->vsync_op == 2)
			env->vsync_op = 0;
	}
	if ((env->gpu == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->gpu_op++;
		if (env->gpu_op == 2)
			env->gpu_op = 0;
	}
	if ((env->text_q == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->text_q_op++;
		if (env->text_q_op == 3)
			env->text_q_op = 0;
	}
}
