/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:20:59 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:29:47 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_lst	*ft_new_elt(char *str)
{
	t_lst		*new;

	new = (t_lst *)malloc(sizeof(*new));
	new->str = ft_strdup(str);
	new->select = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

void	ft_add_list_last(t_lst **list, t_lst *new)
{
	if ((*list)->next == *list)
	{
		(*list)->next = new;
		(*list)->prev = new;
		new->next = *list;
		new->prev = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = *list;
		((*list)->prev)->next = new;
		(*list)->prev = new;
	}
}

void	ft_add_list_first(t_lst **list, t_lst *new)
{
	if ((*list)->next == *list)
	{
		(*list)->next = new;
		(*list)->prev = new;
		new->next = *list;
		new->prev = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = *list;
		((*list)->prev)->next = new;
		(*list)->prev = new;
	}
	*list = new;
}

int		ft_del_elt(t_lst **list, t_lst *elt, t_data *d)
{
	if (*list == NULL)
		return (0);
	if (elt->next == elt)
	{
		if (*list == elt)
			*list = NULL;
		free(elt);
		d->nb_elt--;
		return (0);
	}
	else
	{
		if (*list == elt)
			*list = elt->next;
		elt->prev->next = elt->next;
		elt->next->prev = elt->prev;
		free(elt);
		d->nb_elt--;
		return (1);
	}
}

t_lst	**get_lst(char **av, t_data *d)
{
	t_lst			**list;
	t_lst			*tmp;

	list = (t_lst **)malloc(sizeof(t_lst *));
	d->len = (int)ft_strlen(*av);
	tmp = ft_new_elt(*av);
	d->nb_elt = 1;
	*list = tmp;
	av++;
	while (*av != '\0')
	{
		d->len = (d->len < (int)ft_strlen(*av)) ? (int)ft_strlen(*av) : d->len;
		tmp = ft_new_elt(*av);
		ft_add_list_last(list, tmp);
		d->nb_elt++;
		av++;
	}
	return (list);
}
