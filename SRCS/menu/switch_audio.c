/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_audio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:55:56 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/22 16:55:59 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_audio_1(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->audio_volume == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_music = 1;
		env->audio_volume = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->audio_music == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_music = 0;
		env->audio_effect = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->audio_effect == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_effect = 0;
		env->audio_apply = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_audio_2(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->audio_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_apply = 1;
		env->audio_return = 0;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->audio_apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_apply = 0;
		env->audio_effect = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->audio_effect == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_effect = 0;
		env->audio_music = 1;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_audio_3(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_s) && (env->audio_return == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_return = 0;
		env->audio_volume = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_w) && (env->audio_volume == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_volume = 0;
		env->audio_return = 1;
		env->events.type = SDL_KEYUP;
	}
	else if ((env->events.key.keysym.sym == SDLK_s) && (env->audio_apply == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_return = 1;
		env->audio_apply = 0;
		env->events.type = SDL_KEYUP;
	}
}

void	switch_audio_4(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.8) 
					&& (env->cursy < (env->res_hight / 5) * 2.4))
		{
			env->audio_volume = 0;
			env->audio_music = 0;
			env->audio_effect = 1;
			env->audio_apply = 0;
			env->audio_return = 0;
		}
	}
}

void	switch_audio_5(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 4) 
					&& (env->cursy < (env->res_hight / 5) * 4.5))
		{
			env->audio_volume = 0;
			env->audio_music = 0;
			env->audio_effect = 0;
			env->audio_apply = 0;
			env->audio_return = 1;
		}
	}
}

void	switch_audio_op(t_env *env)
{
	if (env->audio_menu == 1)
	{
		switch_audio_1(env);
		switch_audio_2(env);
		switch_audio_3(env);
		switch_audio_4(env);
		switch_audio_5(env);
		switch_audio_6(env);
		switch_audio_7(env);
		switch_audio_8(env);
		switch_audio_9(env);
		change_volume(env);
		change_effect(env);
		change_music(env);
		exit_from_audio(env);
	}
}
