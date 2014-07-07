/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_elem_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:28:34 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:28:35 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list				*ft_lst_get_elem_at(t_list *alst, unsigned int nbr)
{
	unsigned int	i;
	t_list			*list;

	i = 1;
	list = alst;
	while (list != NULL && i < nbr)
	{
		list = list->next;
		i++;
	}
	if (list == NULL)
		return (NULL);
	else
		return (list);
}
