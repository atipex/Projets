/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:32:13 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:32:14 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*ptr;

	ch = (char)c;
	ptr = NULL;
	if (s[0] == ch)
	{
		return ((char*)s);
	}
	while (*s++)
	{
		if (*s == ch)
		{
			ptr = (char*)s;
		}
	}
	return (ptr);
}
