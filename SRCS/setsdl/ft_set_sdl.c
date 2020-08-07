/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:16:01 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 17:22:09 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		menu_events_list_2(t_env *env, t_sdl *sdl, t_elem *floor)
{
	if(env->audio_menu == 1)
	{
		audio_menu(sdl, env);
		switch_audio_op(env);
		
	}
	if (env->gameplay_menu == 1)
	{
		gameplay_menu(sdl, env);
		switch_gameplay_op(env, floor);
	}
	if (env->play_menu == 1)
	{
		switch_play_op(env);
		play_menu(env);
		
	}
	if (env->story_menu == 1)
	{
		story_menu(env);
		switch_story_op(env);
	}
	if (env->arcade_menu == 1)
	{
		switch_arcade_op(env);
		arcade_menu(env);
	}
	if (env->multi_menu == 1)
	{
		multi_menu(env);
		switch_multi_op(env);
	}
	exit_from_control(env);
	control_menu(env);
	ft_cursor(env);
}

static void		ft_initgame(t_env *env, t_elem *floor)
{
	ft_initraycasting(floor);
	SDL_SetWindowGrab(env->win, SDL_TRUE);
	SDL_WarpMouseInWindow(env->win, env->res_width / 2, env->res_hight / 2);
	ft_initcolors(env, floor);
	ft_initfps(floor, env);
	ft_init_texture(floor);
	
}

int				ft_init_events(t_env *env, t_sdl *sdl, t_elem *floor)
{
	while (1)
	{
		SDL_WaitEvent(&env->events);
		menu_events_list(env, sdl, floor);
		if (exit_from_menu(env) == 1)
			return (1);
		if (env->apply_video_op == 1)
			break ;
		if (env->play_ready == 1)
			break ;
		SDL_RenderPresent(env->ren);
	}
	if (env->apply_video_op == 1)
		apply_video_option2(sdl, env, floor);
	if (env->play_ready == 1)
		ft_display_game(env, floor);
	if (env->play == 1)
		ft_init_events(env, sdl, floor);
	return (1);
}

void			menu_events_list(t_env *env, t_sdl *sdl, t_elem *floor)
{
	if (env->menu == 1)
	{
		interface_menu(env);
		switch_menu(env);
		open_options(env);
		open_play_content(env);
	}
	if (env->op_menu == 1)
	{
		switch_option(env);
		open_video(env);
		exit_from_option(env);
		open_gameplay(env);
		open_audio(env);
		option_menu(env);
	}
	if (env->vid_menu == 1)
	{
		switch_video_op(env);
		back_to_option(env);
		video_menu(sdl, env);
		change_video_option1(env);
		change_video_option2(env);
		change_video_option3(env);
		change_video_option4(env);
		apply_video_option(env);
	}
	menu_events_list_2(env, sdl, floor);
}

int				ft_set_sdl(t_sdl *sdl, t_env *env, t_elem *floor)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	SDL_ShowCursor(SDL_DISABLE);
	env->win = ft_create_window(sdl);
	if (env->win == NULL)
		ft_error(INIT_WIN);
	SDL_GetWindowBrightness(env->win);
	env->ren = ft_init_renderer(env->win, sdl);
	TTF_Init();
	get_max_res(sdl);
	if (!(env->surf = SDL_CreateRGBSurfaceWithFormat(0, env->res_width,
		env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	floor->icon = ft_load_texture("./RSCS/icon/wolf_icon.bmp");
	SDL_SetWindowIcon(env->win, floor->icon);
	ft_initgame(env, floor);
	ft_init_events(env, sdl, floor);
	return (0);
}


