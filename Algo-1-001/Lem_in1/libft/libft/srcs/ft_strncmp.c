/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 11:59:58 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:44:03 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
		{
			if ((*(unsigned char *) s1 - *(unsigned char *) s2) > 0)
				return (1);
			else
				return (-1);
		}
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

