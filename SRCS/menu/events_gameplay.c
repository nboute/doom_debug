/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_gameplay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:34:45 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 17:34:47 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	change_difficulty(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) 
		&& (env->game_difficulty == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->dif_op++;
		if (env->dif_op == 3)
			env->dif_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->game_difficulty == 1) 
		&& (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->dif_op++;
		if (env->dif_op == 3)
			env->dif_op = 0;
	}
}

void	change_sensitivity(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) 
		&& (env->game_sensitivity == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->sens_value++;
		if (env->sens_value == 10)
			env->sens_value = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->game_sensitivity == 1) 
		&& (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->sens_value++;
		if (env->sens_value == 10)
			env->sens_value = 1;
	}
}

void	open_controls(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) 
		&& (env->game_controls == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->show_controls = 1;
		env->game_controls = 0;
		env->gameplay_menu = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->game_controls == 1) 
		&& (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->show_controls = 1;
		env->gameplay_menu = 0;
		env->game_controls = 0;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	exit_from_gameplay(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) 
		&& (env->game_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->ex_opt = 1;
		env->op_menu = 1;
		env->game_return = 0;
		env->gameplay_menu = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->game_return == 1) 
		&& (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->ex_opt = 1;
		env->op_menu = 1;
		env->game_return = 0;
		env->gameplay_menu = 0;
		env->events.type = SDL_MOUSEBUTTONUP;
	}
}

void	apply_gameplay(t_env *env, t_elem *floor)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->game_apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
		floor->sensitivity_setup = env->sens_value;
	if ((env->game_apply == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
		floor->sensitivity_setup = env->sens_value;
}
