/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:01:24 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:01:26 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

void		free_map(int **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i = i + 1;
	}
}

void		free_func(t_functions *list)
{
	t_functions	*tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
