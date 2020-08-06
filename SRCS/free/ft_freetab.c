/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:37:30 by dlartigu          #+#    #+#             */
/*   Updated: 2019/11/27 15:37:31 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/prog.h"

void		ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&(tab[i]));
		i++;
	}
	ft_memdel((void **)&(tab));
}

void		ft_freebigtab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_freetab(tab[i]);
		i++;
	}
	ft_memdel((void **)&(tab));
}
