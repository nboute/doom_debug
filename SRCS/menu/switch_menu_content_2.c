/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_menu_content_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:23:33 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:09:28 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void	switch_play_4(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6)
			&& (env->cursx < (env->res_width / 6 * 5))
				&& (env->cursy > (env->res_hight / 3) * 1.4)
					&& (env->cursy < (env->res_hight / 3) * 1.7))
		{
			env->play_story = 0;
			env->play_arcade = 1;
			env->play_multi = 0;
			env->play_return = 0;
		}
	}
}

void	switch_play_5(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6)
			&& (env->cursx < (env->res_width / 6 * 5))
				&& (env->cursy > (env->res_hight / 3) * 1.7)
					&& (env->cursy < (env->res_hight / 3) * 2))
		{
			env->play_story = 0;
			env->play_arcade = 0;
			env->play_multi = 1;
			env->play_return = 0;
		}
	}
}

void	switch_play_6(t_env *env)
{
	if (env->events.type == SDL_MOUSEMOTION)
	{
		if ((env->cursx > env->res_width / 6)
			&& (env->cursx < (env->res_width / 6 * 5))
				&& (env->cursy > (env->res_hight / 3) * 2)
					&& (env->cursy < (env->res_hight / 3) * 2.3))
		{
			env->play_story = 0;
			env->play_arcade = 0;
			env->play_multi = 0;
			env->play_return = 1;
		}
	}
}
