/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_content_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:08:30 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/05 20:47:45 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		choose_res(t_sdl *sdl, t_env *env)
{
	if (env->res_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 2, sdl->res_hight / 5.35,
			sdl->res_width / 8, sdl->res_hight / 9);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "640 x 480",
			env->red)))
		{
			ft_putendl("choose_res 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
			ft_putendl("/n11/n");
			exit(0);
		}
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
		{
			SDL_FreeSurface(env->surf2);
			env->surf2 = NULL;
		}
		if (env->text2)
		{
			SDL_DestroyTexture(env->text2);
			env->text2 = NULL;
		}
	}
	else if (env->res_op == 2)
	{
		set_ttf_rect(env, sdl->res_width / 2, sdl->res_hight / 5.4,
			sdl->res_width / 6.8, sdl->res_hight / 9);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "THE HIGHEST",
			env->red)))
		{
			ft_putendl("choose_res 2/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
			ft_putendl("/n12/n");
			exit(0);
		}
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
		{
			SDL_FreeSurface(env->surf2);
			env->surf2 = NULL;
		}
		if (env->text2)
		{
			SDL_DestroyTexture(env->text2);
			env->text2 = NULL;
		}
	}
}

void	choose_vsync(t_sdl *sdl, t_env *env)
{
	if (env->vsync_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
		{
			ft_putendl("choose_vsync 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
			ft_putendl("/n13/n");
			exit(0);
		}
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
		{
			SDL_FreeSurface(env->surf2);
			env->surf2 = NULL;
		}
		if (env->text2)
		{
			SDL_DestroyTexture(env->text2);
			env->text2 = NULL;
		}
	}
	else if (env->vsync_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
		{
			ft_putendl("choose_vsync 2/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
			ft_putendl("/n14/n");
			exit(0);
		}
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
		{
			SDL_FreeSurface(env->surf2);
			env->surf2 = NULL;
		}
		if (env->text2)
		{
			SDL_DestroyTexture(env->text2);
			env->text2 = NULL;
		}
	}
}

void	error_option(t_sdl *sdl, t_env *env)
{
	if (env->error_vid == 1)
	{
		set_ttf_rect(env, sdl->res_width / 3, sdl->res_hight / 3,
			sdl->res_width / 15, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "error test", env->red)))
		{
			ft_putendl("error_option 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
			ft_putendl("/n15/n");
			exit(0);
		}
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
		{
			SDL_FreeSurface(env->surf2);
			env->surf2 = NULL;
		}
		if (env->text2)
		{
			SDL_DestroyTexture(env->text2);
			env->text2 = NULL;
		}
		env->error_vid = 0;
	}
}