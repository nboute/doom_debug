/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_audio_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:07:21 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/22 17:07:23 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_audio_6(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > env->res_hight / 5) 
					&& (env->cursy < (env->res_hight / 5) * 1.5))
		{
			env->audio_volume = 1;
			env->audio_music = 0;
			env->audio_effect = 0;
			env->audio_apply = 0;
			env->audio_return = 0;
		}
	}
}

void	switch_audio_7(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 1.5) 
					&& (env->cursy < (env->res_hight / 5) * 1.8))
		{
			env->audio_volume = 0;
			env->audio_music = 1;
			env->audio_effect = 0;
			env->audio_apply = 0;
			env->audio_return = 0;
		}
	}
}

void	switch_audio_8(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 3.9) 
			&& (env->cursx < (env->res_width / 1.35)) 
				&& (env->cursy > (env->res_hight / 5) * 3.4) 
					&& (env->cursy < (env->res_hight / 5) * 4))
		{
			env->audio_volume = 0;
			env->audio_music = 0;
			env->audio_effect = 0;
			env->audio_apply = 1;
			env->audio_return = 0;
		}
	}
}

void	switch_audio_9(t_env *env)
{
	if ((env->events.key.keysym.sym == SDLK_w) && (env->audio_music == 1)
			&& (env->events.type == SDL_KEYDOWN))
	{
		env->audio_volume = 1;
		env->audio_music = 0;
		env->events.type = SDL_KEYUP;
	}
}
