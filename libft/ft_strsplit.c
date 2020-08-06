/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:53 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/08 11:07:48 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t    ft_strclen(const char *str, char c)
{
    size_t    i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);
}

static size_t    ft_word_count(char const *s, char c)
{
    size_t        i;
    size_t        words;

    i = 0;
    words = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            words++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return (words);
}

char            **ft_strsplit(char const *s, char c)
{
    size_t        words;
    char        **tab;
    size_t        i;
    size_t        j;

    if (!s)
        return (NULL);
    words = ft_word_count(s, c);
    if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            if (!(tab[j++] = ft_strndup(s + i, ft_strclen(s + i, c))))
                return (NULL);
            i += ft_strclen(s + i, c);
        }
        else
            i++;
    }
    tab[j] = NULL;
    return (tab);
}