/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:03:12 by mrebours            #+#    #+#             */
/*   Updated: 2014/01/07 21:35:52 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		val;
	int		sign;

	sign = 1;
	val = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			val = val * 10 + ((int) *str - '0');
		else
			return (sign * val);
		str++;
	}
	return (sign * val);
}

