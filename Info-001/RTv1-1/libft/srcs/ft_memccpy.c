/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:29:50 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:29:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*tmp;
	char			*tmp2;
	size_t			i;
	unsigned char	var;

	i = 0;
	var = (unsigned char)c;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	while (i < n)
	{
		if (tmp2[i] == c)
		{
			tmp[i] = tmp2[i];
			i++;
			return (tmp + i);
		}
		tmp[i] = tmp2[i];
		i++;
	}
	return (NULL);
}
