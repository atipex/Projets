/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:29:26 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:34:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*str;

	str = (void*)malloc(size * sizeof(void));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
