/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:29:53 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:29:54 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	char	d;

	src = (char *)s;
	d = c;
	while (n--)
	{
		if (*src == d)
			return (void*)src;
		src++;
	}
	return (NULL);
}
