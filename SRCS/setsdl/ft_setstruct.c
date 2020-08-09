/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:10:01 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 08:00:08 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_set_sdlstruct2(t_sdl *sdl, t_env *env)
{
	if (env->res_op == 1)
	{
		sdl->res_width = 640;
		sdl->res_hight = 480;
		env->res_width = 640;
		env->res_hight = 480;
	}
	else if (env->res_op == 2)
	{
		sdl->res_width = sdl->w_max;
		sdl->res_hight = sdl->h_max;
		env->res_width = sdl->w_max;
		env->res_hight = sdl->h_max;
	}
}

static void		ft_set_sdlstruct3(t_sdl *sdl, t_env *env)
{
	if (env->fs_op == 0 && env->res_op == 1)
	{
		sdl->windowed = 1;
		sdl->fullscreen = 0;
		sdl->windowed_resize_full = 0;
		sdl->fullscreen_maxres = 0;
	}
	else if (env->fs_op == 1 && env->res_op == 1)
	{
		sdl->windowed = 0;
		sdl->fullscreen = 1;
		sdl->windowed_resize_full = 0;
		sdl->fullscreen_maxres = 0;
	}
}

static void		ft_set_sdlstruct4(t_sdl *sdl, t_env *env)
{
	if (env->fs_op == 0 && env->res_op == 2)
	{
		sdl->windowed = 0;
		sdl->fullscreen = 0;
		sdl->windowed_resize_full = 1;
		sdl->fullscreen_maxres = 0;
	}
	else if (env->fs_op == 1 && env->res_op == 2)
	{
		sdl->windowed = 0;
		sdl->fullscreen = 0;
		sdl->windowed_resize_full = 0;
		sdl->fullscreen_maxres = 1;
	}
}

void			ft_set_sdlstruct(t_sdl *sdl, t_env *env)
{
	ft_set_sdlstruct2(sdl, env);
	ft_set_sdlstruct3(sdl, env);
	ft_set_sdlstruct4(sdl, env);
	if (env->gpu_op == 0)
		sdl->hard_accel = 0;
	else
		sdl->hard_accel = 1;
	if (env->vsync_op == 0)
		sdl->vsync = 0;
	else
		sdl->vsync = 1;
}

void			set_events_struct(t_env *env)
{
	env->option = 0;
	env->menu = 1;
	env->res = 0;
	env->play = 1;
	env->exit = 0;
	env->op_menu = 0;
	env->ex_opt = 0;
	env->audio = 0;
	env->video = 0;
	env->controls = 0;
	env->gameplay = 0;
	env->vsync_op = 0;
	env->res_op = 1;
	env->fs_op = 0;
	env->gpu_op = 0;
	env->aliasing_op = 0;
	env->text_q_op = 0;
	env->intro = 1;
	env->sens_value = 1;
	env->int_volume_value = 5;
}
