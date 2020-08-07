/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_video_op_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:24:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/06 17:09:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			apply_video_option(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->apply == 1)
		&& (env->events.type == SDL_KEYDOWN) && (env->vid_menu == 1))
	{
		env->apply_video_op = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->apply == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN) 
		&& (env->vid_menu == 1))
	{
		env->apply_video_op = 1;
	}
}

static void		apply_video_option3(t_sdl *sdl, t_env *env, t_elem *floor)
{
	if (env->aliasing_op == 1)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	}
	env->win = ft_create_window(sdl);
	SDL_GetWindowBrightness(env->win);
	SDL_SetWindowGrab(env->win, SDL_TRUE);
	SDL_ShowCursor(SDL_DISABLE);
	env->ren = ft_init_renderer(env->win, sdl);
	if (env->ren == NULL)
	{
		ft_video_op_error(sdl, env);
	}
	ft_init_events(env, sdl, floor);
}

void			apply_video_option2(t_sdl *sdl, t_env *env, t_elem *floor)
{
	env->apply_video_op = 0;
	SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	SDL_DestroyWindow(env->win);
	env->win = NULL;
	SDL_Quit();
	ft_set_sdlstruct(sdl, env);
	if (env->text_q_op == 0)
		floor->texture_res = 1;
	if (env->text_q_op == 1)
		floor->texture_res = 2;
	if (env->text_q_op == 2)
		floor->texture_res = 3;
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_sdl_error("apply_video_options2 1");
	if (SDL_Init(SDL_INIT_TIMER))
		ft_sdl_error("apply_video_options2 1");
	apply_video_option3(sdl, env, floor);
}