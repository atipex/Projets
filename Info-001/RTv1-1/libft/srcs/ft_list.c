/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:28:30 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:36:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

list		*ft_new_list(int data)
{
	list	*new;

	new = malloc(sizeof(new));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

list		*ft_add_end_list(list *l, int data)
{
	list	*tmp;

	tmp = l;
	if (l != NULL)
	{
		while (l->next != NULL)
			l = l->next;
		l->next = ft_new_list(data);
	}
	else
	{
		l = ft_new_list(data);
		return (l);
	}
	return (tmp);
}
