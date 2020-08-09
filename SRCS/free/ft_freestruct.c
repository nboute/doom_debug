/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/09 07:44:25 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void				ft_free_tab_telem(t_elem *floor)
{
	int		i;

	i = 0;
	while (i < floor->max_floor)
	{
		ft_freetab(&floor[i].box);
		ft_freebigtab(&floor[i].map);
		ft_freebigtab(&floor[i].new);
		i++;
	}
	ft_memdel((void **)&floor);
}

void				ft_free_surface_tab(SDL_Surface ***surfaces)
{
	int		i;

	i = 0;
	if (surfaces == NULL || *surfaces == NULL)
		return ;
	while ((*surfaces)[i])
	{
		ft_free_surface(&((*surfaces)[i]));
		i++;
	}
	ft_memdel((void**)surfaces);
}

void				ft_free_env_1(t_env *env)
{
	ft_free_surface(&env->cursorsurf);
	ft_free_texture(&env->cursortext);
	ft_free_texture(&env->fpstext);
	ft_free_texture(&env->text);
	ft_free_texture(&env->text2);
	ft_free_surface(&env->surf);
	ft_free_surface(&env->surf2);
	ft_free_surface_tab(&env->wall_texture);
	ft_free_surface(&env->floor_texture);
	ft_free_surface(&env->ceiling_texture);
	ft_free_surface(&env->icon);
	ft_free_surface_tab(&env->weapon);
	if (env->ren != NULL)
		SDL_DestroyRenderer(env->ren);
	env->ren = NULL;
	if (env->win != NULL)
		SDL_DestroyWindow(env->win);
	env->win = NULL;
	ft_free_texture(&env->bmpTex);
	ft_free_texture(&env->fontTex);
}

void				ft_free_env_2(t_env *env)
{
	ft_free_texture(&env->fontTex2);
	ft_free_surface(&env->bmpSurf);
	ft_free_surface(&env->texte);
	if (env->police != NULL)
		TTF_CloseFont(env->police);
	env->police = NULL;
	if (env->police2 != NULL)
		TTF_CloseFont(env->police2);
	env->police2 = NULL;
	ft_memdel((void**)&env->sensitivity_value);
	ft_memdel((void**)&env->char_volume_value);
}

void				ft_free_floor(t_elem **floor)
{
	if (!floor || !*floor)
		return ;
	if ((*floor)->fpsfont != NULL)
		TTF_CloseFont((*floor)->fpsfont);
	(*floor)->fpsfont = NULL;
	ft_free_surface(&(*floor)->fpssurf);
	ft_free_texture(&(*floor)->fpstext);
	if ((*floor)->box != NULL)
		ft_freetab(&(*floor)->box);
	if ((*floor)->map != NULL)
		ft_freebigtab(&(*floor)->map);
	if ((*floor)->new != NULL)
		ft_freebigtab(&(*floor)->new);
	ft_free_surface(&(*floor)->surf);
	ft_free_texture(&(*floor)->text);
	ft_free_surface_tab(&(*floor)->walltext);
	ft_free_surface_tab(&(*floor)->floortext);
	ft_free_surface(&(*floor)->skybox);
	ft_free_surface_tab(&(*floor)->ceilingtext);
	ft_free_surface(&(*floor)->icon);
	ft_free_surface_tab(&(*floor)->weapon);
	ft_memdel((void**)floor);
}

void				ft_free_map_struct(t_map *map)
{
	map->floor = NULL;
	ft_memdel((void**)&(map->line));
	ft_memdel((void**)&(map->tmp));
}

void				ft_free_structs(t_env *env, t_map *map, t_elem *floor)
{
	ft_free_env_1(env);
	ft_free_env_2(env);
	ft_free_floor(&floor);
	ft_free_map_struct(map);
	ft_exit_sdl(env);
}
