/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:37:30 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/07 16:40:20 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_freetab(char ***tab)
{
	int		i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		ft_memdel((void **)&((*tab)[i]));
		i++;
	}
	ft_memdel((void **)tab);
}

void		ft_freebigtab(char ****tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		ft_freetab(&(*tab)[i]);
		i++;
	}
	ft_memdel((void **)tab);
}
