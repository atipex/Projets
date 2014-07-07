/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 14:02:15 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:20:25 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

t_list		*ft_del_one_env(t_list *obj)
{
	t_list		*before;
	t_list		*after;

	before = obj->prev;
	after = obj->next;
	if (before == NULL)
	{
		after->prev = NULL;
		return (after);
	}
	else if (after == NULL)
		before->next = NULL;
	else if (before != NULL && after != NULL)
	{
		before->next = after;
		after->prev = before;
	}
	obj = start_obj(obj);
	return (obj);
}

t_list		*ft_lets_unsetenv(t_list *obj, char *cmd)
{
	while (obj->next != NULL)
	{
		if (ft_strcmp(obj->key_word, cmd) == 0)
		{
			obj = ft_del_one_env(obj);
			return (obj);
		}
		obj = obj->next;
	}
	if (obj->next == NULL && (ft_strcmp(obj->key_word, cmd) == 0))
	{
		obj = ft_del_one_env(obj);
		return (obj);
	}
	return (obj);
}

t_list		*ft_unsetenv(t_list *obj, char **cmd)
{
	int			i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 2)
		obj = ft_lets_unsetenv(obj, cmd[1]);
	else
		return (obj);
	return (obj);
}

