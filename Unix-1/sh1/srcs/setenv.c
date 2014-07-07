/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:00:24 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 18:23:15 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftminishell1.h"

t_list		*new_ins_ev(t_list *obj, char **cmd)
{
	obj->value = cmd[2];
	return (obj);
}

t_list		*ft_bzero_env(t_list *obj, char **cmd)
{
	char	*swap;

	while (obj->next != NULL && (ft_strcmp(obj->key_word, cmd[1]) != 0))
		obj = obj->next;
	if (obj->next != NULL)
	{
		obj->value = '\0';
		return (obj);
	}
	if (obj->next == NULL && (ft_strcmp(obj->key_word, cmd[1]) != 0))
	{
		swap = ft_strnew(0);
		swap = ft_strjoin(swap, cmd[1]);
		swap = ft_strjoin(swap, "=");
		obj = fill_obj(obj, swap);
		free(swap);
		return (obj);
	}
	return (obj);
}

t_list		*ft_setenv(t_list *obj, char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 1)
		ft_print_env(obj);
	else if (i == 2)
		obj = ft_bzero_env(obj, cmd);
	else if (i >= 3)
	{
		obj = ft_bzero_env(obj, cmd);
		obj = new_ins_ev(obj, cmd);
	}
	return (obj);
}

