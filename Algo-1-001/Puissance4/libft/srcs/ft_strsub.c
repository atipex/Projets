/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:45:22 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/10 23:23:57 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *) malloc(sizeof(s1) * (len + 1));
	if (s1 && s)
	{
		s2 = s1;
		while (start-- > 0)
			s++;
		while (len-- > 0)
			*s1++ = *s++;
		*s1 = '\0';
	}
	else
		return (NULL);
	return (s2);
}

