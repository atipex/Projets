/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:02:00 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:02:02 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

static t_map	*create_elem(char *str, int line)
{
	t_map		*new;

	new = NULL;
	if ((new = (t_map*)malloc(sizeof(*new))))
	{
		new->line = line;
		new->str = str;
		new->next = NULL;
	}
	return (new);
}

int				push_map(t_map **map, char *str, int line)
{
	t_map		*tmp;

	tmp = *map;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if ((tmp->next = create_elem(str, line)))
			return (0);
	}
	else
	{
		if ((*map = create_elem(str, line)))
			return (0);
	}
	ft_puterror(ALLOC_ERROR);
	return (FAILED);
}

void			free_list(t_map *list)
{
	t_map		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
