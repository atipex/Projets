/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 11:58:20 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/11 21:21:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_nb_word(char const *s, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if ((is_word == 0) && (*s != c))
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int		ft_word_len(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		index;

	if (s)
	{
		index = 0;
		nb_word = ft_nb_word(s, c);
		tab = (char **) malloc(sizeof(char *) * (ft_nb_word(s, c) + 1));
		if (!tab)
			return (NULL);
		while (nb_word--)
		{
			while (*s == c && *s != '\0')
				s++;
			tab[index] = ft_strsub(s, 0, ft_word_len(s, c));
			if (tab[index] == NULL)
				return (NULL);
			s = s + ft_word_len(s, c);
			index++;
		}
		tab[index] = NULL;
		return (tab);
	}
	return (NULL);
}

