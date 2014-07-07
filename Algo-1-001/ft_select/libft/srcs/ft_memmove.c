/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:14:04 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/11 00:58:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*c1;
	char	*c2;

	if (!s1 || !s2 || n == 0)
		return (s1);
	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	c1 = (char *) s1 + n;
	c2 = (char *) s2 + n;
	while (n-- > 0)
		*--c1 = *--c2;
	return (s1);
}

