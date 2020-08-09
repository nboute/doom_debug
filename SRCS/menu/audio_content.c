/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:26:11 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:42:24 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	exit_from_audio(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->audio_return == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->ex_opt = 1;
		env->op_menu = 1;
		env->audio_return = 0;
		env->audio_menu = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->audio_return == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->ex_opt = 1;
		env->op_menu = 1;
		env->audio_return = 0;
		env->audio_menu = 0;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	choose_volume(t_sdl *sdl, t_env *env)
{
	if (env->char_volume_value)
		ft_strdel(&env->char_volume_value);
	if (!(env->char_volume_value = ft_itoa(env->int_volume_value)))
	{
		ft_fct_error("itoa");
	}
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.5,
		sdl->res_width / 22, sdl->res_hight / 14);
	if (!(env->surf2
		= TTF_RenderText_Blended(env->police2,
			env->char_volume_value, env->red)))
		ft_ttf_error(NULL);
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		ft_sdl_error(NULL);
	SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
	if (env->surf2)
		ft_free_surface(&env->surf2);
	if (env->text2)
		ft_free_texture(&env->text2);
}

void	choose_music(t_sdl *sdl, t_env *env)
{
	if (env->music_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.7,
			sdl->res_width / 10, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
			ft_ttf_error(NULL);
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error(NULL);
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->music_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.7,
			sdl->res_width / 15, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_music_3");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("choose_music_4");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void	choose_effect(t_sdl *sdl, t_env *env)
{
	if (env->effect_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.8,
			sdl->res_width / 10, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "OFF", env->red)))
			ft_ttf_error("choose_effect_1");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("choose_effect_2");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
	else if (env->effect_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 2.8,
			sdl->res_width / 15, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "ON", env->red)))
			ft_ttf_error("choose_effect_3");
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
			ft_sdl_error("choose_effect_4");
		SDL_RenderCopy(env->ren, env->text2, NULL, &env->pos2);
		if (env->surf2)
			ft_free_surface(&env->surf2);
		if (env->text2)
			ft_free_texture(&env->text2);
	}
}

void	audio_menu(t_sdl *sdl, t_env *env)
{
	if (env->audio_menu == 1)
	{
		set_ttf(env);
		if (env->audio_volume == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(AUDIO_VOLUME)))
				ft_sdl_error(NULL);
		}
		else if (env->audio_music == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(AUDIO_MUSIC)))
				ft_sdl_error(NULL);
		}
		else if (env->audio_effect == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(AUDIO_EFFEECT)))
				ft_sdl_error(NULL);
		}
		else if (env->audio_apply == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(AUDIO_APPLY)))
				ft_sdl_error(NULL);
		}
		else if (env->audio_return == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(AUDIO_RETURN)))
				ft_sdl_error(NULL);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			ft_sdl_error("audio_menu 2");
		if (env->texte)
			ft_free_surface(&env->texte);
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
			ft_free_texture(&env->fontTex);
		choose_volume(sdl, env);
		choose_effect(sdl, env);
		choose_music(sdl, env);
	}
}