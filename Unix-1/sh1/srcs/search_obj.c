/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:15:45 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:16:47 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

t_list		*search_in_obj(t_list *obj, char *srch)
{
	while (obj->next != NULL)
	{
		if (ft_strcmp(obj->key_word, srch) == 0)
			return (obj);
		obj = obj->next;
	}
	if (obj->next == NULL && (ft_strcmp(obj->key_word, srch) == 0))
		return (obj);
	return (NULL);
}

