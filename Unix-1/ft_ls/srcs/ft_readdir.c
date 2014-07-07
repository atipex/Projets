/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:47:35 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 11:48:46 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

void				ft_lstdir(t_list **lst, t_option *opt, char *path)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*new;

	new = NULL;
	(void)new;
	dir = opendir(path);
	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] != '.' || (dp->d_name[0] == '.' && opt->a == '1'))
		{
			if (path[ft_strlen(path) - 1] != '/')
				path = ft_strjoin(path, "/");
			ft_list_files(ft_strjoin(path, dp->d_name), lst);
		}
	}
	closedir(dir);
}

void				ft_printlst(t_list *file, t_option *opt)
{
	if (opt->r == '1' && file->next)
		ft_printlst(file->next, opt);
	while (file)
	{
		if (file->content)
		{
			if (opt->l == '1')
				ft_printl(((t_data *)(file->content)));
			else
				ft_putendl(((t_data *)(file->content))->path);
		}
		if (opt->r == '1')
			return ;
		file = file->next;
	}
}

void				ft_callsort(t_list *files, t_option *opt)
{
	ft_lstsort_asc(files);
	ft_lstiter(files, *ft_lststat);
	if (opt->t == '1')
		ft_lstsort_time(files);
}
