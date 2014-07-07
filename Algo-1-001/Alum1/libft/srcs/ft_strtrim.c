/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:24:07 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:09:25 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strtrim(const char *s)
{
	int		i;
	int		e;
	int		j;
	char	*dst;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '\t')
		i++;
	j = i;
	while (s[j] && s[j + 1])
		j++;
	e = j;
	while (s[e] == ' ' || s[e] == '\n' || s[e] == ',' || s[e] == '\t')
		e--;
	if ((dst = (char *)malloc(sizeof(char *) * (j - (j - e) - i) + 1)) == 0)
		return (NULL);
	j = 0;
	while (i <= e)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}

