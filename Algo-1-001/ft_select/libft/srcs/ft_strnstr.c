/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 12:03:12 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:43:40 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s2);
	if (!s1 || !s2 || !n)
		return (NULL);
	if (len > n)
		return (NULL);
	if (!*s2)
		return (NULL);
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

