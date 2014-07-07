/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:36:26 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:36:27 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

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
