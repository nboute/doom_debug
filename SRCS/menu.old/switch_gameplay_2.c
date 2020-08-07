/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_gameplay_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:25:44 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 17:25:50 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_gameplay_6(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.8) 
					&& (env->cursy < (env->res_hight / 5) * 2.3))
		{
			env->game_difficulty = 0;
			env->game_sensitivity = 0;
			env->game_controls = 1;
			env->game_apply = 0;
			env->game_return = 0;
		}
	}
}

void	switch_gameplay_7(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.3) 
					&& (env->cursy < (env->res_hight / 5) * 3.9))
		{
			env->game_difficulty = 0;
			env->game_sensitivity = 0;
			env->game_controls = 0;
			env->game_apply = 1;
			env->game_return = 0;
		}
	}
}

void	switch_gameplay_8(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.5) 
					&& (env->cursy < (env->res_hight / 5) * 1.8))
		{
			env->game_difficulty = 0;
			env->game_sensitivity = 1;
			env->game_controls = 0;
			env->game_apply = 0;
			env->game_return = 0;
		}
	}
}

void	switch_gameplay_op(t_env *env, t_elem *floor)
{
	if (env->gameplay_menu == 1)
	{
		switch_gameplay_1(env);
		switch_gameplay_2(env);
		switch_gameplay_3(env);
		switch_gameplay_3(env);
		switch_gameplay_4(env);
		switch_gameplay_5(env);
		switch_gameplay_6(env);
		switch_gameplay_7(env);
		switch_gameplay_8(env);
		change_difficulty(env);
		change_sensitivity(env);
		exit_from_gameplay(env);
		apply_gameplay(env, floor);
		open_controls(env);
	}
}