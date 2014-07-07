/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 16:07:17 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 17:57:03 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_return(char **line, char **save)
{
	size_t	len;
	char	*tmp;

	len = ft_strchr(*save, '\n') - *save;
	*line = ft_strsub(*save, 0, len);
	tmp = *save;
	*save = ft_strsub(tmp, len + 1, ft_strlen(tmp) - len - 1);
	free(tmp);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*save;

	if (fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (save == NULL)
	{
		if ((save = ft_strnew(BUFF_SIZE + 1)) == NULL)
			return (-1);
	}
	while (save != NULL && ft_strchr(save, '\n') == NULL
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (ret == 0 && ft_strchr(save, '\n') == NULL)
	{
		*line = ft_strdup(save);
		return (0);
	}
	ft_return(line, &(save));
	return (1);
}

