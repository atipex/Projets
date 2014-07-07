/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:51:11 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/11 00:33:06 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*s;
	char	*s1;

	s = (char *) malloc(sizeof(s) * size);
	if (s)
	{
		s1 = s;
		while (size > 0)
		{
			*s = 0;
			s++;
			size--;
		}
	}
	else
		return (NULL);
	return (s1);
}

