/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:50:30 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:50:30 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (char *)malloc(sizeof(s1) * (ft_strlen(s) + 1));
	i = 0;
	if (s1 && f)
	{
		s2 = s1;
		while (*s != '\0')
		{
			*s1++ = f(i, *s++);
			i++;
		}
	}
	else
		return (NULL);
	return (s2);
}
