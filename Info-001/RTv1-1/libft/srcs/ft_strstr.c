/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:32:37 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:32:39 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp;

	tmp = (char*)s1;
	if (!(*s2))
		return ((char*)s1);
	while (*tmp)
	{
		tmp1 = (char*)tmp;
		tmp2 = (char*)s2;
		while ((*tmp && *tmp2) && (*tmp == *tmp2))
		{
			tmp++;
			tmp2++;
		}
		if (!*tmp2)
			return (tmp1);
		tmp = tmp1 + 1;
	}
	return (NULL);
}
