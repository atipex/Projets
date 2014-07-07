/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:43:13 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 11:43:14 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include "ft_ls.h"

void	ft_printdir(t_list *file, t_option *opt)
{
	t_list	*new;

	new = NULL;
	if (opt->r == '1' && file->next)
		ft_printdir(file->next, opt);
	while (file)
	{
		if (file->content
			&& S_ISDIR(((t_data *)(file->content))->stat->st_mode))
		{
			ft_lstdir(&new, opt, ((t_data *)(file->content))->path);
			ft_callsort(new, opt);
			ft_lstiter(new, *ft_changepath);
			ft_printlst(new, opt);
		}
		if (opt->r == '1')
			return ;
		file = file->next;
	}
}

void	ft_changepath(t_list *elem)
{
	char	*path;
	char	*begin;

	if ((begin = ft_strrchr(((t_data *)elem->content)->path + 1, '/')))
	{
		path = ft_strdup(&begin[1]);
		free(((t_data *)elem->content)->path);
		((t_data *)elem->content)->path = path;
	}
}
