/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_video_op_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:48:58 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/04 19:50:51 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_video_op_10(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 2.7) 
					&& (env->cursy < (env->res_hight / 5) * 3.1))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 1;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}

void	switch_video_op_11(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.1) 
					&& (env->cursy < (env->res_hight / 5) * 3.5))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 1;
			env->apply = 0;
			env->ret_op = 0;
		}
	}
}
void	switch_video_op_12(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.5) 
					&& (env->cursy < (env->res_hight / 5) * 3.9))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 1;
			env->ret_op = 0;
		}
	}
}
void	switch_video_op_13(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.9) 
					&& (env->cursy < (env->res_hight / 5) * 4.3))
		{
			env->res = 0;
			env->vsync = 0;
			env->fullscreen = 0;
			env->gpu = 0;
			env->aliasing = 0;
			env->text_q = 0;
			env->apply = 0;
			env->ret_op = 1;
		}
	}
}

void	switch_video_op(t_env *env)
{
	if (env->vid_menu == 1)
	{
		switch_video_op_1(env);
		switch_video_op_2(env);
		switch_video_op_3(env);
		switch_video_op_4(env);
		switch_video_op_5(env);
		switch_video_op_6(env);
		switch_video_op_7(env);
		switch_video_op_8(env);
		switch_video_op_9(env);
		switch_video_op_10(env);
		switch_video_op_11(env);
		switch_video_op_12(env);
		switch_video_op_13(env);
	}
}
