/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:50:36 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:50:37 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*c1;

	if (!s1 || !s2 || !n)
		return (s1);
	c1 = s1;
	while (*c1++ != '\0')
		;
	c1--;
	while (*s2 != '\0' && n > 0)
	{
		*c1++ = *s2++;
		n--;
	}
	*c1 = '\0';
	return (s1);
}
