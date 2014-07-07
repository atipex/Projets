/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:29:15 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:29:16 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstsort(t_list **root)
{
	int		loop;
	t_list	*list;

	list = *root;
	loop = 1;
	while (loop)
	{
		loop = 0;
		list = *root;
		while (list && list->next != NULL)
		{
			if (ft_strcmp(list->content, list->next->content) > 0)
			{
				ft_lstswap(list, list->next);
				loop = 1;
			}
			list = list->next;
		}
	}
}
