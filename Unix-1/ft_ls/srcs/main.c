/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:48:55 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 11:49:01 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_opt(t_option *opt)
{
	opt->rec = '0';
	opt->l = '0';
	opt->a = '0';
	opt->r = '0';
	opt->t = '0';
	opt->end = '0';
}

int		main(int argc, char **argv)
{
	int			i;
	t_list		*files;
	t_option	opt;

	i = 1;
	files = NULL;
	ft_init_opt(&opt);
	while (i < argc)
	{
		ft_parse(argv[i], &opt, &files);
		i++;
	}
	if (!files)
	{
		ft_lstdir(&files, &opt, ".");
		ft_callsort(files, &opt);
		ft_lstiter(files, *ft_changepath);
		ft_printlst(files, &opt);
		return (0);
	}
	ft_callsort(files, &opt);
	ft_printfiles(files, &opt);
	ft_printdir(files, &opt);
	return (0);
}
