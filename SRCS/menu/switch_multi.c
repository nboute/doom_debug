/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:51:09 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 17:51:11 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static void		switch_multi_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->multi_map == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->multi_map = 0;
		env->multi_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->multi_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->multi_map = 1;
		env->multi_return = 0;
	}
}	

static void		switch_multi_2(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > env->res_hight / 3) 
					&& (env->cursy < (env->res_hight / 3) * 1.4))
		{
			env->multi_map = 1;
			env->multi_return = 0;
		}
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > (env->res_hight / 3) * 2) 
					&& (env->cursy < (env->res_hight / 3) * 2.3))
		{
			env->multi_map = 0;
			env->multi_return = 1;
		}
	}
}	

static void		switch_multi_3(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->multi_map == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->multi_map = 0;
		env->multi_return = 1;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->multi_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->multi_return = 0;
		env->multi_map = 1;
	}
}

void			switch_multi_op(t_env *env)
{
	if(env->multi_menu == 1)
	{
		switch_multi_1(env);
		switch_multi_2(env);
		switch_multi_3(env);
		exit_from_multi(env);
	}
}
