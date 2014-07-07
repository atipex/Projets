/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:25:28 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:15:01 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

char		*ret_path(t_list *obj)
{
	while (obj->next != NULL && ft_strcmp("PATH", obj->key_word) != 0)
		obj = obj->next;
	if (obj->next == NULL)
		return (NULL);
	return (obj->value);
}

char		**recup_path(t_list *obj)
{
	char		**path_user;
	char		*path_swap;

	path_user = NULL;
	path_swap = ft_strnew(0);
	path_swap = ft_strjoin(path_swap, ret_path(obj));
	path_user = ft_strsplit(path_swap, ':');
	return (path_user);
}

