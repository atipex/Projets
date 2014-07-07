/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:36:10 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:36:12 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(s1) * (ft_strlen(s) + 1));
	if (s1 && f)
	{
		s2 = s1;
		while (*s != '\0')
			*s1++ = f(*s++);
	}
	else
		return (NULL);
	return (s2);
}
