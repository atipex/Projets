/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:51:30 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:51:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(s1) * (len + 1));
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
