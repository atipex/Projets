/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:02:31 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:02:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "wolf.h"

int				ft_puterror(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (FAILED);
	while (str[i])
		write(2, &str[i++], 1);
	return (FAILED);
}

void			ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i = i + 1;
	return (i);
}

void			swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				val_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
