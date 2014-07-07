/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   by: mrebours <mrebours@student.42.fr>               +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2014/01/15 16:58:09 by mrebours             #+#    #+#            */
/*   Updated: 2014/02/01 20:08:51 by mrebours            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static int	verif(char *file)
{
	if (try_ext(file) == 0)
		return (0);
	if (try_file(file) == 0)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_def();
		if (verif(argv[1]))
		{
			ft_putendl("Good");
			return (1);
		}
		return (0);
	}
	ft_putendl_fd("You need an assembly file \".s\"", 2);
	return (0);
}

