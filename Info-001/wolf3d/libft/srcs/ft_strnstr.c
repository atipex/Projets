/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:51:07 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:51:07 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(s2);
	if (!s1 || !s2 || !n)
		return (NULL);
	if (len > n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (*s1 && i <= (n - len))
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
		i++;
	}
	return (NULL);
}
