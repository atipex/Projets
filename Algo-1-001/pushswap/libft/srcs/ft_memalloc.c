/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:29:00 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:29:01 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

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
			s++;
			size--;
		}
	}
	else
		return (NULL);
	return (s1);
}
