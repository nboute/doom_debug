/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_content_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:08:30 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/06 17:49:29 by user42           ###   ########.fr       */
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
			ft_ttf_error("choose_res 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n11/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->res_op == 2)
	{
		set_ttf_rect(env, sdl->res_width / 2, sdl->res_hight / 5.4,
			sdl->res_width / 6.8, sdl->res_hight / 9);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "THE HIGHEST",
			env->red)))
			ft_ttf_error("choose_res 2/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n12/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void	choose_vsync(t_sdl *sdl, t_env *env)
{
	if (env->vsync_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
			sdl->res_width / 12, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
			ft_ttf_error("choose_vsync 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n13/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->vsync_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
			sdl->res_width / 17, sdl->res_hight / 14);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_vsync 2/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n14/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void	error_option(t_sdl *sdl, t_env *env)
{
	if (env->error_vid == 1)
	{
		set_ttf_rect(env, sdl->res_width / 3, sdl->res_hight / 3,
			sdl->res_width / 15, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "error test", env->red)))
			ft_ttf_error("error_option 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("/n15/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
		env->error_vid = 0;
	}
}