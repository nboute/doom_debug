/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:14:15 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:09:06 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_menu_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->play == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play = 0;
		env->mapedit = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->mapedit == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->option = 1;
		env->mapedit = 0;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->option == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->option = 0;
		env->exit = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->exit == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->exit = 0;
		env->play = 1;
	}
}

void	switch_menu_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->play == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->play = 0;
		env->exit = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->mapedit == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->mapedit = 0;
		env->play = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->option == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->option = 0;
		env->mapedit = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->exit == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->exit = 0;
		env->option = 1;
	}
}

void	switch_menu_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) && (env->cursx
			< (env->res_width / 6 * 5)) && (env->cursy > env->res_hight / 3)
			&& (env->cursy < (env->res_hight / 3) * 1.4))
		{
			env->play = 1;
			env->mapedit = 0;
			env->option = 0;
			env->exit = 0;
		}
		if ((env->cursx > env->res_width / 6) && (env->cursx
			< (env->res_width / 6 * 5)) && (env->cursy > (env->res_hight / 3)
			* 1.4) && (env->cursy < (env->res_hight / 3) * 1.7))
		{
			env->play = 0;
			env->mapedit = 1;
			env->option = 0;
			env->exit = 0;
		}
		if ((env->cursx > env->res_width / 6) && (env->cursx
			< (env->res_width / 6 * 5)) && (env->cursy > (env->res_hight / 3)
			* 1.7) && (env->cursy < (env->res_hight / 3) * 2.1))
		{
			env->play = 0;
			env->mapedit = 0;
			env->option = 1;
			env->exit = 0;
		}
		if ((env->cursx > env->res_width / 6) && (env->cursx
			< (env->res_width / 6 * 5)) && (env->cursy > (env->res_hight / 3)
			* 2.1) && (env->cursy < (env->res_hight / 3) * 2.4))
		{
			env->play = 0;
			env->mapedit = 0;
			env->option = 0;
			env->exit = 1;
		}
	}
}
