/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:09:38 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/05 20:47:17 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		ft_cursor_down(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_keydown.bmp")) < 0)
	{
		ft_putendl("ft_cursor_down");
		ft_putendl(SDL_GetError());
		exit(0);
	}
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
	{
		ft_putendl(SDL_GetError());
		ft_putendl("/n16/n");
		exit(0);
	}
	if (env->cursorsurf)
	{
		SDL_FreeSurface(env->cursorsurf);
		env->cursorsurf = NULL;
	}
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
	{
		SDL_DestroyTexture(env->cursortext);
		env->cursortext = NULL;
	}
	SDL_RenderPresent(env->ren);
}

static void		ft_cursor_motion(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_wolf1.bmp")) < 0)
	{
		ft_putendl(SDL_GetError());
		ft_putendl("/n17/n");
		exit(0);
	}
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
	{
		ft_putendl("ft_cursor_motion/n");
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (env->cursorsurf)
	{
		SDL_FreeSurface(env->cursorsurf);
		env->cursorsurf = NULL;
	}
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
	{
		SDL_DestroyTexture(env->cursortext);
		env->cursortext = NULL;
	}
	SDL_RenderPresent(env->ren);
}

static void		ft_cursor_up(t_env *env)
{
	if ((env->cursorsurf = SDL_LoadBMP("RSCS/cursor/cursor_wolf1.bmp")) < 0)
	{
		ft_putendl(SDL_GetError());
		ft_putendl("/n18/n");
		exit(0);
	}
	env->rectcursor.x = env->cursx - 12;
	env->rectcursor.y = env->cursy - 2;
	env->rectcursor.w = 16;
	env->rectcursor.h = 16;
	if (!(env->cursortext = SDL_CreateTextureFromSurface(env->ren, env->cursorsurf)))
	{
		ft_putendl("ft_cursor_up/n");
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (env->cursorsurf)
	{
		SDL_FreeSurface(env->cursorsurf);
		env->cursorsurf = NULL;
	}
	SDL_RenderCopy(env->ren, env->cursortext, NULL, &env->rectcursor);
	if (env->cursortext)
	{
		SDL_DestroyTexture(env->cursortext);
		env->cursortext = NULL;
	}
	SDL_RenderPresent(env->ren);
}

void    ft_cursor(t_env *env)
{
	if (env->events.type == SDL_MOUSEBUTTONDOWN
		|| env->events.type == SDL_MOUSEBUTTONUP)
	{
		env->cursx = env->events.button.x;
		env->cursy = env->events.button.y;
		printf("%d|%d\n", env->cursx, env->cursy);
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
