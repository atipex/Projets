/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:31:37 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:31:38 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*strnew;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	len = (size_t)ft_strlen(s);
	strnew = ft_strnew(len);
	i = 0;
	while (s[i] != '\0')
	{
		strnew[i] = (*f)(s[i]);
		i++;
	}
	return (strnew);
}
