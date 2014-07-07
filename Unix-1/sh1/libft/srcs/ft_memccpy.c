/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:29:10 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:29:11 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*c1;
	const char	*c2;

	if (s1 && s2 && n)
	{
		c1 = (char *)s1;
		c2 = (char *)s2;
		while (n-- > 0)
		{
			*c1++ = *c2++;
			if (*(c1 - 1) == c)
				return (c1);
		}
	}
	return (0);
}
