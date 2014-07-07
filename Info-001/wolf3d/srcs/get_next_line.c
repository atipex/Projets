/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:01:34 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:08:30 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf.h"
#define BUF_SIZE 1

char				*re_alloc(char *str)
{
	char			*str2;
	int				i;

	i = 0;
	if ((str2 = malloc((ft_strlen(str) + 2) * sizeof(char))) == NULL)
		ft_putstr("Error with an allocation");
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i + 1] = '\0';
	free(str);
	return (str2);
}

char				*get_next_line(const int fd)
{
	int				i;
	int				size;
	static char		buf[BUF_SIZE];
	char			*str;

	i = 0;
	size = 0;
	if ((str = malloc(sizeof(char))) == NULL)
		ft_putstr("Error with an allocation");
	str[0] = '\0';
	while ((size = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
	{
		str = re_alloc(str);
		str[i] = buf[0];
		i++;
	}
	if (size == 0 && i == 0)
		return (NULL);
	else
		return (str);
}
