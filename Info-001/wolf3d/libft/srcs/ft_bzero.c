/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:45:31 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:45:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_temp;
	size_t			count;

	s_temp = s;
	count = 0;
	while (count < n)
	{
		s_temp[count] = 0;
		count += 1;
	}
}
