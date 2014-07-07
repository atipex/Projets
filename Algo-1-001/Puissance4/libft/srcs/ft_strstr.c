/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:28:06 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:43:16 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		length;

	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return ((char *) s1);
	length = ft_strlen(s2);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, length) == 0)
			return ((char *) s1);
		s1++;
	}
	return (NULL);
}

