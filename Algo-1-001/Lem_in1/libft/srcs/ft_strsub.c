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
	char	*str;
	char	*s_conv;
	int		i;

	if (s == NULL)
		return (0);
	str = ft_strnew(len);
	s_conv = (char *)s;
	i = 0;
	if (str)
	{
		while (len)
		{
			str[i] = s_conv[start + i];
			len--;
			i++;
		}
	}
	return (str);
}
