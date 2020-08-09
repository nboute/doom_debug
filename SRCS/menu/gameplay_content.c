/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:55:39 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:42:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		choose_difficulty_2(t_sdl *sdl, t_env *env)
{
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
		sdl->res_width / 10, sdl->res_hight / 12);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "HARD", env->red)))
		ft_ttf_error("choose_difficulty_2 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("choose_difficulty_2 2/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			choose_difficulty(t_sdl *sdl, t_env *env)
{
	if (env->dif_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
			sdl->res_width / 10, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "EASY", env->red)))
			ft_ttf_error("choose_difficulty 1/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("choose_difficulty 2/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->dif_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
			sdl->res_width / 8, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "NORMAL", env->red)))
			ft_ttf_error("choose_difficulty 3/n");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("choose_difficulty 4/n");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->dif_op == 2)
		choose_difficulty_2(sdl, env);
}

void			choose_sensitivity(t_sdl *sdl, t_env *env)
{
	if (env->sensitivity_value)
		ft_strdel(&env->sensitivity_value);
	if (!(env->sensitivity_value = ft_itoa(env->sens_value)))
	{
		ft_fct_error("itoa");
	}
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
		sdl->res_width / 22, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->sensitivity_value, env->red)))
		ft_ttf_error("choose_sensitivity 1/n");
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error("choose_sensitivity 2/n");
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void			gameplay_menu(t_sdl *sdl, t_env *env)
{
	if (env->gameplay_menu == 1)
	{
		set_ttf(env);
		if (env->game_difficulty == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(GAME_DIF)))
				ft_sdl_error(NULL);
		}
		else if (env->game_sensitivity == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(GAME_SENS)))
				ft_sdl_error(NULL);
		}
		else if (env->game_controls == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(GAME_CONTROL)))
				ft_sdl_error(NULL);
		}
		else if (env->game_apply == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(GAME_APPLY)))
				ft_sdl_error(NULL);
		}
		else if (env->game_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(GAME_RETURN)))
				ft_sdl_error(NULL);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			ft_sdl_error("gameplay_menu 2/n");
		if (env->texte)
		{
			ft_free_surface(&env->texte);
		}
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
		ft_free_texture(&env->fontTex);
		choose_difficulty(sdl, env);
		choose_sensitivity(sdl, env);
	}
}