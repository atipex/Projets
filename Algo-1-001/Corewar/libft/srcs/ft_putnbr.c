/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:29:09 by mrebours            #+#    #+#             */
/*   Updated: 2014/01/12 07:14:41 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_aff(int nb, int signe)
{
	if (nb / 10)
		ft_aff(nb / 10, signe);
	ft_putchar('0' + signe * (nb % 10));
}

void			ft_putnbr(int n)
{
	int		signe;

	signe = 1;
	if (n < 0)
	{
		ft_putchar('-');
		signe = -1;
	}
	ft_aff(n, signe);
}

