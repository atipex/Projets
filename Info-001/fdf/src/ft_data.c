/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:19:26 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:19:30 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static t_pts	*ft_create_elem(int x, int y, int z)
{
	t_pts		*new;

	new = (t_pts *)malloc(sizeof(t_pts));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

static void		ft_list_push_back(int x, int y, int z, t_pts **pts)
{
	t_pts		*ptr;

	ptr = *pts;
	if (*pts == NULL)
		*pts = ft_create_elem(x, y, z);
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_create_elem(x, y, z);
	}
}

static void		ft_free_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

t_pts			*ft_save_data(int fd, int *xnbr, int *ynbr)
{
	t_pts		*pts;
	char		*line;
	char		**tab;
	int			x;
	int			y;

	pts = NULL;
	x = 0;
	y = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (tab[x])
		{
			ft_list_push_back(x, y, ft_atoi(tab[x]), &pts);
			x++;
		}
		*xnbr = x;
		ft_free_tab(tab);
		y++;
		x = 0;
	}
	*ynbr = y;
	return (pts);
}
