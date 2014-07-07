/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:41:57 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:41:58 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_tabsort(char **tab, int n)
{
	int		i;
	int		loop;
	char	*tmp;

	i = 0;
	loop = 1;
	while (loop)
	{
		i = 0;
		loop = 0;
		while (i < n - 1 && tab[i + 1] != NULL)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab [i + 1] = tmp;
				loop = 1;
			}
			i++;
		}
	}
}
