/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 13:28:07 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:45:02 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_aff_fd(int nb, int signe, int fd)
{
	if (nb / 10)
		ft_aff_fd(nb / 10, signe, fd);
	ft_putchar_fd('0' + signe * (nb % 10), fd);
}

void			ft_putnbr_fd(int nb, int fd)
{
	int		signe;

	signe = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		signe = -1;
	}
	ft_aff_fd(nb, signe, fd);
}

