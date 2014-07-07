/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:39:11 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 11:41:36 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include "ft_ls.h"

static void	ft_prtstaterror(char *path)
{
	char		*error;

	error = strerror(errno);
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putendl(error);
}

void		ft_list_files(char *path, t_list **files)
{
	t_list		*new;

	if (!(new = ft_lstnew(path, sizeof(char) * (ft_strlen(path) + 1))))
		exit(-1);
	ft_lstadd(files, new);
}

void		ft_lstswap(t_list *elem1, t_list *elem2)
{
	void		*tmp;

	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
}

void		ft_lstsort_asc(t_list *files)
{
	int			sort;
	t_list		*run;

	sort = 0;
	run = files;
	while (sort != 1 && run)
	{
		sort = 1;
		while (run->next && ft_strcmp(run->content, run->next->content) > 0)
		{
			sort = 0;
			ft_lstswap(run, run->next);
			run = run->next;
		}
		if (sort == 0)
			run = files;
		else if (run->next && sort == 1)
		{
			sort = 0;
			run = run->next;
		}
	}
}

void		ft_lststat(t_list *elem)
{
	struct stat	*file_stat;
	int			ret;
	t_data		*data;

	file_stat = malloc(sizeof(struct stat));
	ret = stat((const char *)elem->content, file_stat);
	if (ret == -1)
	{
		free(file_stat);
		ft_prtstaterror(elem->content);
		free(elem->content);
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		data = malloc(sizeof(t_data));
		data->stat = file_stat;
		data->path = elem->content;
		elem->content = data;
	}
}
