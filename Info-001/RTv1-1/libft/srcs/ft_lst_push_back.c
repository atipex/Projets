/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:28:38 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:28:39 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_list **begin, void *c, size_t content)
{
	t_list	*old;
	t_list	*new;

	old = *begin;
	new = ft_lstnew(c, content + 1);
	if (!old)
		*begin = new;
	else
	{
		while (old->next != NULL)
			old = old->next;
		old->next = new;
	}
}
