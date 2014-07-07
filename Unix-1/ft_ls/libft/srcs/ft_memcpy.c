/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:29:50 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:29:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*c1;
	const char	*c2;

	if (s1 && s1 && n != 0)
	{
		c1 = (char *)s1;
		c2 = (char *)s2;
		while (n-- > 0)
			*c1++ = *c2++;
	}
	return (s1);
}
