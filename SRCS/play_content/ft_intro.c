/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:25 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:14:36 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	ft_init_intro(t_env *env)
{
	env->rect_intro.x = env->res_width / 8;
	env->rect_intro.y = env->res_hight / 1.2;
	env->color.r = 255;
	env->color.g = 255;
	env->color.b = 255;
	env->color.a = 0;
	if (env->police2)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	if (!(env->police2 = TTF_OpenFont("./RSCS/fonts/ARCADECLASSIC.TTF", 60)))
	{
		ft_ttf_error(NULL);
	}
	SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
	SDL_RenderClear(env->ren);
	SDL_RenderPresent(env->ren);
	env->introstep = 0;
}

void	ft_intro(t_env *env)
{
	ft_init_intro(env);
	env->timer2 = SDL_AddTimer(500, ft_speak, env);
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	while (env->introstep != 10)
	{
		ft_intro_content_p1(env);
		ft_intro_content_p2(env);
		ft_intro_content_p3(env);
		ft_intro_content_p4(env);
		ft_intro_content_p5(env);
	}
	SDL_RemoveTimer(env->timer2);
	env->intro = 0;
}

Uint32	ft_speak(Uint32 intervalle, void *param)
{
	t_env *env;
	env = param;
	env->introstep++;
	return (intervalle);
}

void	ft_render_intro(t_env *env)
{
	SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
	SDL_RenderCopy(env->ren, env->text, NULL, &env->rect_intro);
	if (env->surf)
		SDL_FreeSurface(env->surf);
	env->surf = NULL;
	if (env->text)
		SDL_DestroyTexture(env->text);
	env->text = NULL;
	SDL_RenderPresent(env->ren);
}

void	ft_baba(t_env *env)
{
	env->rect_baba.x = (env->res_width / 2) - 75;
	env->rect_baba.y = (env->res_hight / 2) - 75;
	env->rect_baba.w = 150;
	env->rect_baba.h = 150;
	if (env->bmpSurf)
	{
		SDL_FreeSurface(env->bmpSurf);
		env->bmpSurf = NULL;
	}
	if ((env->bmpSurf = SDL_LoadBMP("RSCS/play/baba1.bmp")) < 0)
		printf("SDL_load image failed: %s\n", SDL_GetError());
	if (env->bmpTex)
	{
		SDL_DestroyTexture(env->bmpTex);
		env->bmpTex = NULL;
	}
	if (!(env->bmpTex = SDL_CreateTextureFromSurface(env->ren, env->bmpSurf)))
	{
		ft_sdl_error(NULL);
	}
	SDL_RenderCopy(env->ren, env->bmpTex, NULL, &env->rect_baba);
}
