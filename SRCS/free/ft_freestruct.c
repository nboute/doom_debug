/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 03:45:33 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 17:53:18 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void					ft_free_tab_telem(t_elem *floor)
{
	int i;

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
	int	i;

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

void					ft_free_env_1(t_env *env)
{
	int	i = 0;
	printf("|%d\n", i++);
	ft_free_surface(&env->cursorsurf);
	printf("|%d\n", i++);
	ft_free_texture(&env->cursortext);
	printf("|%d\n", i++);
	ft_free_texture(&env->fpstext);
	printf("|%d\n", i++);
	ft_free_texture(&env->text);
	printf("|%d\n", i++);
	ft_free_texture(&env->text2);
	printf("|%d\n", i++);
	ft_free_surface(&env->surf);
	printf("|%d\n", i++);
	ft_free_surface(&env->surf2);
	printf("|%d\n", i++);
	ft_free_surface_tab(&env->wall_texture);
	printf("|%d\n", i++);
	ft_free_surface(&env->floor_texture);
	printf("|%d\n", i++);
	ft_free_surface(&env->ceiling_texture);
	printf("|%d\n", i++);
	ft_free_surface(&env->icon);
	printf("|%d\n", i++);
	ft_free_surface_tab(&env->weapon);
	printf("|%d\n", i++);
	if (env->ren != NULL)
		SDL_DestroyRenderer(env->ren);
	printf("|%d\n", i++);
	env->ren = NULL;
	if (env->win != NULL)
		SDL_DestroyWindow(env->win);
	printf("|%d\n", i++);
	env->win = NULL;
	printf("|%d\n", i++);
	ft_free_texture(&env->bmpTex);
	printf("|%d\n", i++);
	ft_free_texture(&env->fontTex);
}

void					ft_free_env_2(t_env *env)
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

void					ft_free_floor(t_elem **floor)
{
	if (!floor || !*floor)
		return ;
		int	i = 0;
	printf("|%d\n", i++);
	printf("%p\n", (*floor)->fpsfont);
	if ((*floor)->fpsfont != NULL)
		TTF_CloseFont((*floor)->fpsfont);
	printf("|%d\n", i++);
	(*floor)->fpsfont = NULL;
	ft_free_surface(&(*floor)->fpssurf);
	printf("|%d\n", i++);
	ft_free_texture(&(*floor)->fpstext);
	printf("|%d\n", i++);
	ft_memdel((void**)&(*floor)->keystat);
	if ((*floor)->box != NULL)
		ft_freetab(&(*floor)->box);
	if ((*floor)->map != NULL)
		ft_freebigtab(&(*floor)->map);
	if ((*floor)->new != NULL)
		ft_freebigtab(&(*floor)->new);
	printf("|%d\n", i++);
	ft_free_surface(&(*floor)->surf);
	printf("|%d\n", i++);
	ft_free_texture(&(*floor)->text);
	printf("|%d\n", i++);
	ft_free_surface_tab(&(*floor)->walltext);
	printf("|%d\n", i++);
	ft_free_surface_tab(&(*floor)->floortext);
	printf("|%d\n", i++);
	ft_free_surface(&(*floor)->skybox);
	printf("|%d\n", i++);
	ft_free_surface_tab(&(*floor)->ceilingtext);
	printf("|%d\n", i++);
	ft_free_surface(&(*floor)->icon);
	printf("|%d\n", i++);
	ft_free_surface_tab(&(*floor)->weapon);
	printf("|%d\n", i++);
	ft_memdel((void**)floor);
}

void					ft_free_map_struct(t_map *map)
{
	map->floor = NULL;
	ft_memdel((void**)&(map->line));
	ft_memdel((void**)&(map->tmp));
}

void					ft_free_structs(t_env *env, t_map *map, t_elem *floor)
{
	ft_free_env_1(env);
	ft_free_env_2(env);
	ft_free_floor(&floor);
	ft_free_map_struct(map);
	ft_exit_sdl(env);
}