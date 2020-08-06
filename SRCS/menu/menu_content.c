/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:16:44 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 00:12:03 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	interface_menu(t_env *env)
{
	if (env->play == 1)
	{
		if (!(env->texte  = SDL_LoadBMP(PLAY)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
	}
	else if (env->option == 1)
	{
		if (!(env->texte  = SDL_LoadBMP(SET_HOME)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
	}
	else if (env->exit == 1)
	{
		if (!(env->texte  = SDL_LoadBMP(EXIT)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
	}
	else if (env->mapedit == 1)
	{
		if (!(env->texte  = SDL_LoadBMP(MAPEDIT)))
		{
			ft_putendl(SDL_GetError());
			exit(0);
		}
	}
	if (env->menu == 1)
	{
		if (env->texte == NULL)
		{
			ft_putendl("interface_menu 1/n");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		SDL_RenderClear(env->ren);
		if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
		{
			ft_putendl("interface_menu 2/n");
			ft_putendl(SDL_GetError());
			exit(0);
		}
		if (env->texte)
		{
			SDL_FreeSurface(env->texte);
			env->texte = NULL;
		}
		SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
		if (env->fontTex)
		{
			SDL_DestroyTexture(env->fontTex);
			env->fontTex = NULL;
		}
	}
}

void	option_menu(t_env *env)
{
	if (env->op_menu == 1)
	{
		if (env->ex_opt == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(SET_BACK)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->video == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(SET_VIDEO)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->audio == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(SET_AUDIO)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->gameplay == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(SET_GAMEPLAY)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		if (env->op_menu == 1)
		{
			if (env->text == NULL)
			{
				ft_putendl("option_menu 1/n");
				ft_putendl(SDL_GetError());
				exit(0);
			}
			SDL_RenderClear(env->ren);
			if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
			{
				ft_putendl("option_menu 2/n");
				ft_putendl(SDL_GetError());
				exit(0);
			}
			if (env->texte)
			{
				SDL_FreeSurface(env->texte);
				env->texte = NULL;
			}
			SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
			if (env->fontTex)
			{
				SDL_DestroyTexture(env->fontTex);
				env->fontTex = NULL;
			}
		}
	}
}

void	video_menu2(t_sdl *sdl, t_env *env)
{
	if (env->texte == NULL)
	{
		ft_putendl("video_menu 1/n");
		ft_putendl(SDL_GetError());
		exit(0);
	}
	SDL_RenderClear(env->ren);
	if (!(env->fontTex = SDL_CreateTextureFromSurface(env->ren, env->texte)))
	{
		ft_putendl("video_menu 2/n");
		ft_putendl(SDL_GetError());
		exit(0);
	}
	if (env->texte)
	{
		SDL_FreeSurface(env->texte);
		env->texte = NULL;
	}
	SDL_RenderCopy(env->ren, env->fontTex, NULL, NULL);
	if (env->fontTex)
	{
		SDL_DestroyTexture(env->fontTex);
		env->fontTex = NULL;
	}
	choose_res(sdl, env);
	choose_vsync(sdl, env);
	choose_fs(sdl, env);
	choose_gpu(sdl, env);
	choose_aliasing(sdl, env);
	choose_texture(sdl, env);
	error_option(sdl, env);
}

void	video_menu(t_sdl *sdl, t_env *env)
{
	if (env->vid_menu == 1)
	{
		set_ttf(env);
		if (env->res == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_RES)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->vsync == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_VSYNC)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->fullscreen == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_FS)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->gpu == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_GPU)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->aliasing == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_ALIAS)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->text_q == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_TEXTURE)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->ret_op == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_RET)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		else if (env->apply == 1)
		{
			if (!(env->texte  = SDL_LoadBMP(VID_APPLY)))
			{
				ft_putendl(SDL_GetError());
				exit(0);
			}
		}
		video_menu2(sdl, env);
	}
}
