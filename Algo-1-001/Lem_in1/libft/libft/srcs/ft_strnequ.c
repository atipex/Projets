/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:22:21 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:47:17 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2 || n == 0)
		return (0);
	while (*s1 == *s2 && n > 0)
	{
		if (*s1 == '\0')
			return (1);
		s1++;
		s2++;
		n--;
		if (n == 0)
			return (1);
	}
	return (0);
}
