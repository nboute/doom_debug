/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:38:22 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 02:12:26 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void			choose_fs(t_sdl *sdl, t_env *env)
{
	if (env->fs_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.8,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
		{
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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
	else if (env->fs_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.8,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
		{
			ft_putendl("choose_fs/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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

void			choose_gpu(t_sdl *sdl, t_env *env)
{
	if (env->gpu_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.3,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
		{
			ft_putendl("choose_gpu 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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
	else if (env->gpu_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.3,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
		{
			ft_putendl("choose_gpu 2/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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

void			choose_aliasing(t_sdl *sdl, t_env *env)
{
	if (env->aliasing_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
		{
			ft_putendl("choose_aliasing 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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
	else if (env->aliasing_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
		{
			ft_putendl("choose_aliasing 2/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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

static void		choose_texture_2(t_sdl *sdl, t_env *env)
{
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
		sdl->res_width / 10, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "HIGHT", env->red)))
	{
		ft_putendl("choose_texture_2 1/n");
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
	{
		ft_putendl(SDL_GetError());
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

void			choose_texture(t_sdl *sdl, t_env *env)
{
	if (env->text_q_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "LOW", env->red)))
		{
			ft_putendl("choose_texture 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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
	else if (env->text_q_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
			sdl->res_width / 10, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "MEDIUM", env->red)))
		{
			ft_putendl("choose_texture 2/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl(SDL_GetError());
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
	else if (env->text_q_op == 2)
		choose_texture_2(sdl, env);
}

