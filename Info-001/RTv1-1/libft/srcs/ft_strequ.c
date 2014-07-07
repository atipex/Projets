/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:31:18 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:31:21 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	size_t	i;

	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
	{
		return (0);
	}
	while ((s1[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == ft_strlen(s1))
	{
		return (1);
	}
	return (0);
}
