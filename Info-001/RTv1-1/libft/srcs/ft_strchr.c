/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:30:53 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:38:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	while (i < length && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return (&(((char *)s)[i]));
	}
	return (NULL);
}
