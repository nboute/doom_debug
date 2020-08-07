/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:38:22 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/06 17:50:16 by user42           ###   ########.fr       */
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
			ft_ttf_error("/n1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n2/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->fs_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.8,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_fs/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n3/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void			choose_gpu(t_sdl *sdl, t_env *env)
{
	if (env->gpu_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.3,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
			ft_ttf_error("choose_gpu 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n4/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->gpu_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.3,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_gpu 2/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n5/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void			choose_aliasing(t_sdl *sdl, t_env *env)
{
	if (env->aliasing_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
			ft_ttf_error("choose_aliasing 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n6/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->aliasing_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_aliasing 2/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n7/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

static void		choose_texture_2(t_sdl *sdl, t_env *env)
{
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
		sdl->res_width / 10, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "HIGHT", env->red)))
		ft_ttf_error("choose_texture_2 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("/n8/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			choose_texture(t_sdl *sdl, t_env *env)
{
	if (env->text_q_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "LOW", env->red)))
			ft_ttf_error("choose_texture 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n9/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->text_q_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 1.7,
			sdl->res_width / 10, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "MEDIUM", env->red)))
			ft_ttf_error("choose_texture 2/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n10/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->text_q_op == 2)
		choose_texture_2(sdl, env);
}

