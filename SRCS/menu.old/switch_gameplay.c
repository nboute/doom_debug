/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_gameplay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:06:36 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 17:06:39 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_gameplay_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->game_difficulty == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_sensitivity = 1;
		env->game_difficulty = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->game_sensitivity == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_sensitivity = 0;
		env->game_controls = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->game_controls == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_controls = 0;
		env->game_apply = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_gameplay_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->game_return == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_apply = 1;
		env->game_return = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) 
		&& (env->game_controls == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_controls = 0;
		env->game_sensitivity = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) 
		&& (env->game_sensitivity == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_difficulty = 1;
		env->game_sensitivity = 0;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_gameplay_3(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > env->res_hight / 5) 
					&& (env->cursy < (env->res_hight / 5) * 1.5))
		{
			env->game_difficulty = 1;
			env->game_sensitivity = 0;
			env->game_controls = 0;
			env->game_apply = 0;
			env->game_return = 0;
		}
	}
}

void	switch_gameplay_4(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->game_apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_return = 1;
		env->game_apply = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) 
		&& (env->game_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_return = 0;
		env->game_difficulty = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->game_apply == 1)
		&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_apply = 0;
		env->game_controls = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_gameplay_5(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) 
		&& (env->game_difficulty == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->game_difficulty = 0;
		env->game_return = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->events.type == SDL_MOUSEMOTION)
		&& (env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.9) 
					&& (env->cursy < (env->res_hight / 5) * 4.6))
	{	
		env->game_difficulty = 0;
		env->game_sensitivity = 0;
		env->game_controls = 0;
		env->game_apply = 0;
		env->game_return = 1;
	}
}
