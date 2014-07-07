/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   try_file.c                                          :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   by: mrebours <mrebours@student.42.fr>               +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2014/01/15 17:08:34 by mrebours             #+#    #+#            */
/*   Updated: 2014/02/01 20:09:38 by mrebours            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

static int	try_content(int ret, char *buff)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (i++ < ret)
	{
		if ((buff[i] == 0 || buff[i] == 1) && find++ > 25)
		{
			ft_putendl_fd("Bad content in your file .", 2);
			return (0);
		}
	}
	return (1);
}

int			try_ext(char *file)
{
	int		size;

	size = ft_strlen(file);
	if (size > 2 && (ft_strcmp(file + size - 2, ".s") == 0))
		return (1);
	ft_putendl_fd("You need an asm file.", 2);
	return (0);
}

int			try_file(char *file)
{
	int		fd;
	int		ret;
	char	buff[50];

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Can't open this file", 2);
		return (0);
	}
	if ((ret = read(fd, &buff, 50)) <= 0)
	{
		ft_putendl_fd("Fle is empty.", 2);
		close(fd);
		return (0);
	}
	if (!try_content(ret, buff))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

