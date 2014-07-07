/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:52:08 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 03:52:09 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int		find_nl(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (i);
			i++;
			str++;
		}
	}
	return (-1);
}

static char		*get_nl(char **str)
{
	int		i;
	int		pos;
	char	*ret;
	char	*tmp;

	i = 0;
	pos = find_nl(*str);
	if (pos == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(*ret) * (pos + 1));
	if (!ret)
		return (NULL);
	while (i < pos)
	{
		ret[i] = (*str)[i];
		i++;
	}
	ret[i] = '\0';
	tmp = ft_strsub(*str + i + 1, 0, ft_strlen(*str) - ft_strlen(ret));
	free(*str);
	*str = tmp;
	return (ret);
}

static char		*ft_concatenate(char *remain, char *buf)
{
	char		*tmp;

	if (remain)
	{
		tmp = ft_strjoin(remain, buf);
		free(remain);
	}
	else
		tmp = ft_strdup(buf);
	return (tmp);
}

static int		ft_final(char **remain, char **line)
{
	if (*remain && **remain)
	{
		*line = *remain;
		*remain = 0;
		return (1);
	}
	*line = 0;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*remain;
	char		*ret;
	char		buf[BUFF_SIZE];
	int			nbread;
	int			fn;

	while (!(ret = get_nl(&remain)))
	{
		nbread = read(fd, buf, BUFF_SIZE);
		if (nbread == -1)
			return (-1);
		buf[nbread] = '\0';
		if (!nbread)
		{
			fn = ft_final(&remain, line);
			return (fn);
		}
		remain = ft_concatenate(remain, buf);
		if (!remain)
			return (-1);
	}
	*line = ret;
	return (1);
}
