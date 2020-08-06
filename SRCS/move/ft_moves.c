/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:46:11 by dlartigu          #+#    #+#             */
/*   Updated: 2020/06/09 03:46:12 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

static	void		ft_strafe_left(t_elem *floor)
{
	floor->tmpx = floor->posx - ((floor->speed * floor->speedshift)
		* cos(floor->angle - 1.5708));
	if (floor[0].new[(int)floor->posy][(int)floor->tmpx][WALL] != '1')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy - ((floor->speed * floor->speedshift)
		* sin(floor->angle - 1.5708));
	if (floor[0].new[(int)floor->tmpy][(int)floor->posx][WALL] != '1')
		floor->posy = floor->tmpy;
}

static	void		ft_strafe_right(t_elem *floor)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift)
		* cos(floor->angle - 1.5708));
	if (floor[0].new[(int)floor->posy][(int)floor->tmpx][WALL] != '1')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift)
		* sin(floor->angle - 1.5708));
	if (floor[0].new[(int)floor->tmpy][(int)floor->posx][WALL] != '1')
		floor->posy = floor->tmpy;
}

static	void		ft_move_front_back(t_elem *floor, int nb)
{
	floor->tmpx = floor->posx + ((floor->speed * floor->speedshift)
		* cos(floor->angle)) * nb;
	if (floor[0].new[(int)floor->posy][(int)floor->tmpx][WALL] != '1')
		floor->posx = floor->tmpx;
	floor->tmpy = floor->posy + ((floor->speed * floor->speedshift)
		* sin(floor->angle)) * nb;
	if (floor[0].new[(int)floor->tmpy][(int)floor->posx][WALL] != '1')
		floor->posy = floor->tmpy;
}

void				ft_dispminimap(t_env *env, t_elem *floor)
{
	if ((env->events.key.keysym.sym == SDLK_m)
		&& (env->events.type == SDL_KEYUP))
		floor->m = 0;
	if ((env->events.key.keysym.sym == SDLK_m)
		&& (env->events.type == SDL_KEYDOWN))
		floor->m = 1;
}

void				ft_inputs(t_env *env, t_elem *floor)
{
	floor->keystat = SDL_GetKeyboardState(NULL);
	if (floor->keystat[SDL_SCANCODE_W])
		ft_move_front_back(floor, 1);
	if (floor->keystat[SDL_SCANCODE_S])
		ft_move_front_back(floor, -1);
	if (floor->keystat[SDL_SCANCODE_A])
		ft_strafe_left(floor);
	if (floor->keystat[SDL_SCANCODE_D])
		ft_strafe_right(floor);
	ft_dive(floor);
	env->test = 0;
}
