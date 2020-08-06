/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:48:08 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 01:19:50 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_escape(t_env *env, t_elem *floor)
{
	env->play_ready = 0;
	env->play = 1;
	env->menu = 1;
	floor->spawn_x = floor->posx;
	floor->spawn_y = floor->posy;
	SDL_RemoveTimer(env->timer);
	SDL_SetRelativeMouseMode(SDL_FALSE);
}

static	void		ft_renderer(t_env *env, t_elem *floor)
{
	const char *str;
	if (!(floor->fpssurf =
		TTF_RenderText_Solid(floor->fpsfont, floor->fps, floor->fpscolor)))
	{
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (env->text)
	{
		SDL_DestroyTexture(env->text);
		env->text = NULL;
	}
	if (env->fpstext)
	{
		SDL_DestroyTexture(env->fpstext);
		env->fpstext = NULL;
	}
	SDL_RenderClear(env->ren);
	if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
	{
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (!(env->fpstext = SDL_CreateTextureFromSurface(env->ren, floor->fpssurf)))
	{
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	if (floor->fpssurf)
	{
		SDL_FreeSurface(floor->fpssurf);
		floor->fpssurf = NULL;
	}
	if (SDL_RenderCopy(env->ren, env->text, NULL, NULL))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (SDL_RenderCopy(env->ren, env->fpstext, NULL, &env->rectfps))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	ft_crosshair(env);
	SDL_RenderPresent(env->ren);
}

static	void		ft_render(t_env *env, t_elem *floor)
{
	const char *str;
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	if (!(env->surf = SDL_CreateRGBSurfaceWithFormat(0, env->res_width,
		env->res_hight, 32, SDL_PIXELFORMAT_RGBA8888)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	ft_drawrenderer(env, floor);
	ft_inputs(env, floor);
	ft_countfps(floor);
	ft_renderer(env, floor);
}

int					ft_display_game(t_env *env, t_elem *floor)
{
	if (env->intro == 1)
		ft_intro(env);
	ft_countfps(floor);
	ft_printfps(0, floor);
	env->timer = SDL_AddTimer(500, ft_printfps, floor);
	while (1)
	{
		while (SDL_PollEvent(&env->events))
		{
			if (env->events.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				env->play_ready = 0;
				SDL_RemoveTimer(env->timer);
				break;
			}
			ft_movements(env, floor);
		}
		if ((env->events.key.keysym.sym == SDLK_ESCAPE)
			&& (env->play_ready == 1) && (env->events.type == SDL_KEYDOWN))
		{
			ft_escape(env, floor);
			break;
		}
		ft_render(env, floor);
	}
	return (1);
}
