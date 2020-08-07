/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:09:38 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/06 17:15:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_cursor_down(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_keydown.bmp")) < 0)
		ft_sdl_error("ft_cursor_down");
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
		ft_sdl_error("/n16/n");
	if (env->cursorsurf)
		ft_free_surface(&env->cursorsurf);
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
		ft_free_texture(&env->cursortext);
	SDL_RenderPresent(env->ren);
}

static void		ft_cursor_motion(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_wolf1.bmp")) < 0)
		ft_sdl_error("/n17/n");
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
		ft_sdl_error("ft_cursor_motion/n");
	if (env->cursorsurf)
		ft_free_surface(&env->cursorsurf);
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
		ft_free_texture(&env->cursortext);
	SDL_RenderPresent(env->ren);
}

static void		ft_cursor_up(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_wolf1.bmp")) < 0)
		ft_sdl_error("/n18/n");
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
		ft_sdl_error("ft_cursor_up/n");
	if (env->cursorsurf)
		ft_free_surface(&env->cursorsurf);
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
		ft_free_texture(&env->cursortext);
	SDL_RenderPresent(env->ren);
}

void    ft_cursor(t_env *env)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN
		|| env->events.type == SDL_MOUSEBUTTONUP)
	{
		env->cursx = env->events.button.x;
		env->cursy = env->events.button.y;
	}
	else
		SDL_GetMouseState(&env->cursx, &env->cursy);
	if (env->events.type == SDL_MOUSEBUTTONDOWN)
		ft_cursor_down(env);
	if (env->events.type == SDL_MOUSEMOTION)
		ft_cursor_motion(env);
	if (env->events.type == SDL_MOUSEBUTTONUP)
		ft_cursor_up(env);
}
