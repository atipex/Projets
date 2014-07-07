/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:32:16 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:32:19 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrev(const char *s)
{
	char	*ret;
	int		i;
	int		n;

	i = -1;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		++i;
	n = i - 1;
	ret = (char*)malloc(i * sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	while (i >= 0)
	{
		ret[n - i] = s[i];
		i--;
	}
	ret[n + 1] = '\0';
	return (ret);
}
