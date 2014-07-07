/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 04:08:44 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 17:20:12 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftminishell1.h"

char		*cl_to_tab_3(char *key, char *val)
{
	char		*ret;

	ret = ft_strnew(0);
	ret = ft_strjoin(ret, key);
	ret = ft_strjoin(ret, "=");
	ret = ft_strjoin(ret, val);
	return (ret);
}

char		**cl_to_tab_2(char **ret, t_list *obj)
{
	int		i;

	i = 1;
	while (obj->next != NULL)
	{
		i++;
		obj = obj->next;
	}
	if ((ret = (char **) malloc(sizeof(char *) * i + 1)) == NULL)
		exit(0);
	i = 0;
	while (obj->prev != NULL)
	{
		ret[i] = ft_strnew(0);
		ret[i] = ft_strjoin(ret[i], cl_to_tab_3(obj->key_word, obj->value));
		obj = obj->prev;
		i++;
	}
	ret[i] = ft_strnew(0);
	ret[i] = ft_strjoin(ret[i], cl_to_tab_3(obj->key_word, obj->value));
	ret[i + 1] = NULL;
	return (ret);
}

char		**cl_to_tab(t_list *obj)
{
	char	**ret;

	ret = NULL;
	ret = cl_to_tab_2(ret, obj);
	return (ret);
}

