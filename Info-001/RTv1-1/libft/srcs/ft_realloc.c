/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:30:48 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:30:48 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		*ft_realloc(void *ptr, size_t taille)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(taille));
	if (taille == 0)
		return (ptr);
	new_ptr = malloc(taille);
	ft_memcpy(new_ptr, ptr, taille);
	return (new_ptr);
}
