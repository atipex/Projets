/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:39:00 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:12:24 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"

void		ft_lstsort_time(t_list *files)
{
	int			sort;
	t_list		*run;
	time_t		time1;
	time_t		time2;

	sort = 0;
	run = files;
	while (run)
	{
		if (run->next && run->content && run->next->content)
		{
			time1 = ((t_data *)(run->content))->stat->st_mtime;
			time2 = ((t_data *)(run->next->content))->stat->st_mtime;
			if (time1 < time2)
			{
				sort = 1;
				ft_lstswap(run, run->next);
			}
		}
		run = run->next;
	}
	if (sort == 1)
		ft_lstsort_time(files);
}
