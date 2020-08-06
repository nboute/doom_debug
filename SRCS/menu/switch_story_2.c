/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_story_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:35:02 by jcharrou          #+#    #+#             */
/*   Updated: 2020/07/23 18:35:04 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_story_4(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > (env->res_hight / 3) * 1.4) 
					&& (env->cursy < (env->res_hight / 3) * 1.7))
		{
			env->story_normal = 0;
			env->story_hard = 1;
			env->story_hell = 0;
			env->story_return = 0;
		}
	}
}

void	switch_story_5(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > (env->res_hight / 3) * 1.7) 
					&& (env->cursy < (env->res_hight / 3) * 2))
		{
			env->story_normal = 0;
			env->story_hard = 0;
			env->story_hell = 1;
			env->story_return = 0;
		}
	}
}

void	switch_story_6(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6) 
			&& (env->cursx < (env->res_width / 6 * 5)) 
				&& (env->cursy > (env->res_hight / 3) * 2) 
					&& (env->cursy < (env->res_hight / 3) * 2.3))
		{
			env->story_normal = 0;
			env->story_hard = 0;
			env->story_hell = 0;
			env->story_return = 1;
		}
	}
}
