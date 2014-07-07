/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fill_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:52:24 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 17:21:00 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftminishell1.h"

t_list			*start_obj(t_list *obj)
{
	while (obj->prev != NULL)
		obj = obj->prev;
	return (obj);
}

t_list			*fill_obj(t_list *obj_old, char *environ)
{
	t_list		*obj;
	char		**ev_split;

	ev_split = NULL;
	if ((obj = (t_list *) malloc(sizeof(t_list))) == NULL)
		exit(0);
	ev_split = ft_strsplit(environ, '=');
	obj->key_word = ev_split[0];
	obj->value = ev_split[1];
	if (obj_old == NULL)
	{
		obj->prev = NULL;
		obj->next = NULL;
	}
	else
	{
		obj->prev = obj_old;
		obj->next = NULL;
		obj_old->next = obj;
	}
	return (obj);
}

