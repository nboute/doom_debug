/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_audio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:12:28 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/22 17:12:31 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	change_effect(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->audio_effect == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->effect_op++;
		if (env->effect_op == 2)
			env->effect_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->audio_effect == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->effect_op++;
		if (env->effect_op == 2)
			env->effect_op = 0;
	}
}

void	change_music(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->audio_music == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->music_op++;
		if (env->music_op == 2)
			env->music_op = 0;
		env->events.type = SDL_KEYUP;
	}
	if ((env->audio_music == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->music_op++;
		if (env->music_op == 2)
			env->music_op = 0;
	}
}

void	change_volume(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_RETURN) && (env->audio_volume == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->int_volume_value++;
		if (env->int_volume_value == 10)
			env->int_volume_value = 1;
		env->events.type = SDL_KEYUP;
	}
	if ((env->audio_volume == 1) && (env->events.type == SDL_MOUSEBUTTONDOWN))
	{
		env->int_volume_value++;
		if (env->int_volume_value == 10)
			env->int_volume_value = 1;
	}
}
