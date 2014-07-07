/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:32:42 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:41:12 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * (len + 1));
		while (i < (start + len))
		{
			if (i >= start)
				str[i - start] = s[i];
			i++;
		}
		str[len] = '\0';
		return (str);
	}
	else
		return (NULL);
}
