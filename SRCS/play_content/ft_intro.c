/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:37:25 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/06 19:39:54 by niboute          ###   ########.fr       */
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
	if (!(env->police2 = TTF_OpenFont("./RSCS/fonts/ARCADECLASSIC.TTF", 60)))
	{
		ft_putendl(TTF_GetError());
		exit(0);
	}
	printf("LOADED FONT:%p\n", env->police2);
	SDL_SetRenderDrawColor(env->ren, 0, 0, 0, 255);
	SDL_RenderClear(env->ren);
	SDL_RenderPresent(env->ren);
	env->introstep = 0;
}

void	ft_intro(t_env *env)
{
		printf("|A\n");
	ft_init_intro(env);
		printf("|B\n");
	env->timer2 = SDL_AddTimer(500, ft_speak, env);
		printf("|C\n");

	while (env->introstep != 10)
	{
		printf("|D\n");
		ft_intro_content_p1(env);
		printf("|E\n");
		ft_intro_content_p2(env);
		printf("|F\n");
		ft_intro_content_p3(env);
		printf("|G\n");
		ft_intro_content_p4(env);
		printf("|H\n");
		ft_intro_content_p5(env);
		printf("|I\n");
	}
		printf("|J\n");
	SDL_RemoveTimer(env->timer2);
		printf("|K\n");
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
	if ((env->bmpSurf = SDL_LoadBMP("RSCS/play/baba1.bmp")) < 0)
		printf("SDL_load image failed: %s\n", SDL_GetError());
	if (!(env->bmpTex = SDL_CreateTextureFromSurface(env->ren, env->bmpSurf)))
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	SDL_RenderCopy(env->ren, env->bmpTex, NULL, &env->rect_baba);
}
