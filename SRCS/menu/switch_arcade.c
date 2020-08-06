/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_arcade.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:23:34 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/22 16:23:41 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		switch_arcade_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->arcade_map == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->arcade_map = 0;
		env->arcade_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) 
		&& (env->arcade_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->arcade_return = 0;
		env->arcade_map = 1;
	}
}

static void		switch_arcade_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->arcade_map == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->arcade_map = 0;
		env->arcade_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->arcade_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->arcade_map = 1;
		env->arcade_return = 0;
	}
}

static void		switch_arcade_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > env->res_hight / 3) 
					&& (env->cursy < (env->res_hight / 3) * 1.4))
		{
			env->arcade_map = 1;
			env->arcade_return = 0;
		}
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > (env->res_hight / 3) * 2) 
					&& (env->cursy < (env->res_hight / 3) * 2.3))
		{
			env->arcade_map = 0;
			env->arcade_return = 1;
		}
	}
}	

void	switch_arcade_op(t_env *env)
{
	if(env->arcade_menu == 1)
	{
		switch_arcade_1(env);
		switch_arcade_2(env);
		switch_arcade_3(env);
		exit_from_arcade(env);
	}
}