/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:17:20 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 17:16:45 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != c)
	{
	if (*s == '\0')
		return (0);
	s++;
	}
	return ((char *) s);
}

