/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:12:52 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/11 00:39:54 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;

	if (s == NULL)
		return (0);
	s_tmp = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*s_tmp == (unsigned char)c)
			return ((void *) s_tmp);
		s_tmp++;
	}
	return (0);
}

