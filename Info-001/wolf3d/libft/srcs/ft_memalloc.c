/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:46:40 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:46:41 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	char	*s1;

	s = (char *)malloc(sizeof(s) * size);
	if (s)
	{
		s1 = s;
		while (size > 0)
		{
			*s = 0;
			s += 1;
			size -= 1;
		}
	}
	else
		return (NULL);
	return (s1);
}
