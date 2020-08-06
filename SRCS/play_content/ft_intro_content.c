/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:41 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 00:47:54 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void    ft_intro_content_p1(t_env *env)
{
	if (env->introstep == 0)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 60;
		env->rect_intro.h = 50;
		env->surf =
			TTF_RenderText_Blended(env->police2, "Sergei", env->color);
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_render_intro(env);
	}
	if (env->introstep == 1)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 100;
		env->rect_intro.h = 50;
		env->surf =
			TTF_RenderText_Blended(env->police2, "Sergei   !", env->color);
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_render_intro(env);
	}
}

void    ft_intro_content_p2(t_env *env)
{
	if (env->introstep == 2)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 180;
		env->rect_intro.h = 50;
		if (!(env->surf
			= TTF_RenderText_Blended(env->police2, "wake   up   Sergei"
				, env->color)))
		{
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_render_intro(env);
	}
	if (env->introstep == 3)
	{
		SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
		SDL_RenderClear(env->ren);
		ft_baba(env);
		SDL_RenderPresent(env->ren);
		if (env->bmpSurf)
			SDL_FreeSurface(env->bmpSurf);
		env->bmpSurf = NULL;
		if (env->bmpTex)
			SDL_DestroyTexture(env->bmpTex);
		env->bmpTex = NULL;
	}
}

void    ft_intro_content_p3(t_env *env)
{
	if (env->introstep == 4)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 210;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2,
			"I  am   the  BabaYaga", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
	if (env->introstep == 5)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 360;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2,
			"I  summonned  you  from  the  hell", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
}

void    ft_intro_content_p4(t_env *env)
{
	if (env->introstep == 6)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 450;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2,
			"It s  time  to  accomplish  your  purpose", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
	if (env->introstep == 7)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 390;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2,
			"It s  normal  if  you  feel  dizy", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
}

void    ft_intro_content_p5(t_env *env)
{
	if (env->introstep == 8)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 380;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2,
			"You  have  losted  your  memories", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
	if (env->introstep == 9)
	{
		SDL_RenderClear(env->ren);
		env->rect_intro.w = 540;
		env->rect_intro.h = 50;
		if (!(env->surf = TTF_RenderText_Blended(env->police2
			, "Let s  find  them  in  the  maze  of  your  soul", env->color)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (!(env->text = SDL_CreateTextureFromSurface(env->ren, env->surf)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
		ft_baba(env);
		ft_render_intro(env);
	}
}
