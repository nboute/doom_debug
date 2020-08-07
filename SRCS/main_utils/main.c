/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:53:36 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/07 17:52:19 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

int		main(int ac, char **av)
{
	t_sdl	sdl;
	t_map	map;
	t_env	env;

	ft_bzero((void*)&sdl, sizeof(t_sdl));
	ft_bzero((void*)&map, sizeof(t_map));
	ft_bzero((void*)&env, sizeof(t_env));
	if (ac != 2)
		return (ft_error(3));
	if (ft_checkfilename(av[1]) != 0)
		return (ft_error(5));
	map.file = av[1];
	if (ft_parse_map_param(&map) != 0)
	{
		ft_free_structs(&env, &map, map.floor);
//		ft_free_tab_telem(map.floor);
		return (ft_error(4));
	}
	else
	{
		set_events_struct(&env);
		ft_set_sdlstruct(&sdl, &env);
		ft_set_sdl(&sdl, &env, map.floor);
	//	ft_free_tab_telem(map.floor);
	}
	ft_free_structs(&env, &map, map.floor);
	return (0);
}
