/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:28:24 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:28:25 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*putnbr_to_str(char *str, int len, int n, int neg)
{
	str[len--] = '\0';
	if (neg)
		str[0] = '-';
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char		*max_neg(void)
{
	char	*str;
	char	*str2;
	int		i;

	str2 = "-2147483648";
	i = 0;
	str = (char*)malloc(sizeof(char) * 11);
	if (str)
	{
		while (i < 11)
		{
			str[i] = str2[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

int			n_is_neg(int *n, int *len)
{
	if (*n < 0)
	{
		(*len)++;
		*n = *n * -1;
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;
	int		tmp;

	tmp = n;
	len = 0;
	if (n == -2147483648)
		return (max_neg());
	neg = n_is_neg(&n, &len);
	if (tmp == 0)
		len++;
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
		str = putnbr_to_str(str, len, n, neg);
	else
		return (NULL);
	return (str);
}
