/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:27:33 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:27:34 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	total;
	int	signe;
	int	i;

	total = 0;
	i = 0;
	signe = 1;
	while (str[i] < 33)
	{
		i++;
	}
	if ((str[i] == '-') || (str[i] == '+'))
	{
		signe = (str[i++] == '+' ? 1 : -1);
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		total = total * 10 + str[i++] - '0';
	}
	return (signe * total);
}
