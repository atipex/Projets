/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:12:15 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/11 00:50:55 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;

	if (s1 != '\0' && s2 != '\0')
	{
		while (n > 0)
		{
			c1 = (unsigned char *) s1;
			c2 = (unsigned char *) s2;
			if (*c1 != *c2)
				return (*c1 - *c2);
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}

