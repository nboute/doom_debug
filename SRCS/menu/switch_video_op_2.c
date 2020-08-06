/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_video_op_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:33:35 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 16:33:37 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"


void	switch_video_op_5(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->text_q == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->aliasing = 1;
		env->text_q = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->aliasing == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->aliasing = 0;
		env->gpu = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->aliasing == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->aliasing = 0;
		env->text_q = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_video_op_6(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->ret_op == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->res = 1;
		env->ret_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > env->res_hight / 5) 
					&& (env->cursy < (env->res_hight / 5) * 1.5))
		{
			env->res = 1;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}

void	switch_video_op_7(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.5) 
					&& (env->cursy < (env->res_hight / 5) * 1.9))
		{
			env->res = 0;
			env->vsync = 1;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}

void	switch_video_op_8(t_env *env)
{		
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.9) 
					&& (env->cursy < (env->res_hight / 5) * 2.3))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 1;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}

void	switch_video_op_9(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 2.3) 
					&& (env->cursy < (env->res_hight / 5) * 2.7))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 1;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}
