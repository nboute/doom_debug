/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:55:39 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 01:02:53 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		choose_difficulty_2(t_sdl *sdl, t_env *env)
{
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
		sdl->res_width / 10, sdl->res_hight / 12);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "HARD", env->red)))
	{
		ft_putendl("choose_difficulty_2 1/n");
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
	{
		ft_putendl("choose_difficulty_2 2/n");
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

void			choose_difficulty(t_sdl *sdl, t_env *env)
{
	if (env->dif_op == 0)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
			sdl->res_width / 10, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "EASY", env->red)))
		{
			ft_putendl("choose_difficulty 1/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl("choose_difficulty 2/n");
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
	else if (env->dif_op == 1)
	{
		set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 4.7,
			sdl->res_width / 8, sdl->res_hight / 12);
		if (!(env->surf2 = TTF_RenderText_Blended(env->police2, "NORMAL", env->red)))
		{
			ft_putendl("choose_difficulty 3/n");
			ft_putendl(TTF_GetError());
			exit(0);
		}
		if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
		{
			ft_putendl("choose_difficulty 4/n");
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
	else if (env->dif_op == 2)
		choose_difficulty_2(sdl, env);
}

void			choose_sensitivity(t_sdl *sdl, t_env *env)
{
	if (env->sensitivity_value)
		free(env->sensitivity_value);
	env->sensitivity_value = NULL;
	if (!(env->sensitivity_value = ft_itoa(env->sens_value)))
	{
		ft_putendl("itoa");
		exit(0);
	}
	set_ttf_rect(env, sdl->res_width / 1.7, sdl->res_hight / 3.5,
		sdl->res_width / 22, sdl->res_hight / 14);
	if (!(env->surf2 = TTF_RenderText_Blended(env->police2,
		env->sensitivity_value, env->red)))
	{
		ft_putendl("choose_sensitivity 1/n");
		ft_putendl(TTF_GetError());
		exit(0);
	}
	if (!(env->text2 = SDL_CreateTextureFromSurface(env->ren, env->surf2)))
	{
		ft_putendl("choose_sensitivity 2/n");
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

void			gameplay_menu(t_sdl *sdl, t_env *env)
{
	if (env->gameplay_menu == 1)
	{
		set_ttf(env);
		if (env->game_difficulty == 1)
		{
			if (!(env->texte = SDL_LoadBMP(GAME_DIF)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->game_sensitivity == 1)
		{
			if (!(env->texte = SDL_LoadBMP(GAME_SENS)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->game_controls == 1)
		{
			if (!(env->texte = SDL_LoadBMP(GAME_CONTROL)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->game_apply == 1)
		{
			if (!(env->texte = SDL_LoadBMP(GAME_APPLY)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->game_return == 1)
		{
			if (!(env->texte = SDL_LoadBMP(GAME_RETURN)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		{
			ft_putendl("gameplay_menu 2/n");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (env->texte)
		{
			SDL_FreeSurface(env->texte);
			SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		}
		if (env->fontTex)
		{
			SDL_DestroyTexture(env->fontTex);
			env->fontTex = NULL;
		}
		choose_difficulty(sdl, env);
		choose_sensitivity(sdl, env);
	}
}