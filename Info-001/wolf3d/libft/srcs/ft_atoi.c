/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:45:26 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:45:26 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		value;
	int		signe;

	signe = 1;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str += 1;
	if (*str == '-')
	{
		signe = -1;
		str += 1;
	}
	else if (*str == '+')
	{
		str += 1;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			value = value * 10 + ((int)*str - '0');
		else
			return (signe * value);
		str += 1;
	}
	return (signe * value);
}
