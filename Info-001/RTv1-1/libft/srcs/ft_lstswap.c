/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:29:20 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:29:23 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_lstswap(t_list *s1, t_list *s2)
{
	t_list	tmp;
	size_t	size;

	size = sizeof(t_list) - sizeof(t_list*);
	ft_memcpy(&tmp, s1, size);
	ft_memcpy(s1, s2, size);
	ft_memcpy(s2, &tmp, size);
}
