/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:28:35 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:42:58 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (char *) 0;
	if (!s)
		return (last);
	while (*s != 0)
	{
		if (*s == c)
			last = (char *) s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (last);
}

