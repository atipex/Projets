/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:32:49 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:41:38 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int			ft_test_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		j;

	if (s)
	{
		j = 0;
		i = 0;
		str = (char *)malloc(sizeof(char) * (ft_strlen(s)));
		while (ft_test_char(s[i]) == 1)
			i++;
		str = ft_strsub(s, i, ft_strlen(s) - i);
		i = 0;
		while (str[j] != '\0')
		{
			if (ft_test_char(str[j]) == 1)
				i++;
			else
				i = 0;
			j++;
		}
		str = ft_strsub(str, 0, ft_strlen(str) + 1 - i);
		return (str);
	}
	return (NULL);
}
