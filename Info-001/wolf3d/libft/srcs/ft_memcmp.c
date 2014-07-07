/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:47:01 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:47:01 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (s1 != '\0' && s2 != '\0')
	{
		while (n > 0)
		{
			c1 = (unsigned char *)s1;
			c2 = (unsigned char *)s2;
			if (*c1 != *c2)
				return (*c1 - *c2);
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}
