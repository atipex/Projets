/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:27:43 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:27:44 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dllstadd_end(t_dllist **alst, t_dllist *new)
{
	t_dllist	*root;

	root = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	new->prev = (*alst);
	(*alst)->next = new;
	*alst = root;
}
