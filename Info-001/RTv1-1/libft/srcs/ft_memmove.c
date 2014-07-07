/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:30:08 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:30:09 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	const char	*src;
	char		*dest;

	src = s2;
	dest = s1;
	if (dest <= src || src >= (dest + n))
	{
		while (n--)
		{
			*dest++ = *src++;
		}
	}
	else
	{
		src = src + n - 1;
		dest = dest + n - 1;
		while (n--)
		{
			*dest-- = *src--;
		}
	}
	return (s1);
}
