/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:30:11 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:30:16 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c2;
	char			*str;
	size_t			i;

	i = 0;
	c2 = (unsigned char)c;
	str = b;
	while (i < len)
	{
		str[i] = c2;
		i++;
	}
	return (str);
}
