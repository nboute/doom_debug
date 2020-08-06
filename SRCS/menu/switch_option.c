/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:29:07 by jcharrou          #+#    #+#             */
/*   Updated: 2020/01/15 16:28:33 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_option_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->ex_opt == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->video = 1;
		env->ex_opt = 0;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->video == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->video = 0;
		env->audio = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->audio == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio = 0;
		env->gameplay = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->gameplay == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->ex_opt = 1;
		env->gameplay = 0;
	}
}

void	switch_option_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->ex_opt == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->gameplay = 1;
		env->ex_opt = 0;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->video == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->video = 0;
		env->ex_opt = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->audio == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio = 0;
		env->video = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->gameplay == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio = 1;
		env->gameplay = 0;
	}
}

void	switch_option_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) && (env->cursx < (env->res_width / 1.35)) && (env->cursy > env->res_hight / 5) && (env->cursy < (env->res_hight / 5) * 1.8))
		{
			env->video = 1;
			env->audio = 0;
			env->gameplay = 0;
			env->ex_opt = 0;
		}
		if ((env->cursx > env->res_width / 3.9) && (env->cursx < (env->res_width / 1.35)) && (env->cursy > (env->res_hight / 5) * 1.8) && (env->cursy < (env->res_hight / 5) * 2.4))
		{
			env->video = 0;
			env->audio = 1;
			env->gameplay = 0;
			env->ex_opt = 0;
		}
		if ((env->cursx > env->res_width / 3.9) && (env->cursx < (env->res_width / 1.35)) && (env->cursy > (env->res_hight / 5) * 2.4) && (env->cursy < (env->res_hight / 5) * 3))
		{
			env->video = 0;
			env->audio = 0;
			env->gameplay = 1;
			env->ex_opt = 0;
		}
		if ((env->cursx > env->res_width / 3.9) && (env->cursx < (env->res_width / 1.35)) && (env->cursy > (env->res_hight / 5) * 4) && (env->cursy < (env->res_hight / 5) * 4.5))
		{
			env->video = 0;
			env->audio = 0;
			env->gameplay = 0;
			env->ex_opt = 1;
		}
	}
}
