/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:27:57 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:27:59 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_dllist		*ft_dllstnew(void const *content, size_t content_size)
{
	t_dllist	*root;

	root = (t_dllist*)malloc(sizeof(t_dllist));
	if (!root)
		return (NULL);
	root->next = NULL;
	root->prev = NULL;
	root->content = NULL;
	root->content_size = 0;
	if (content)
	{
		root->content = malloc(content_size);
		if (root->content)
		{
			ft_memcpy(root->content, content, content_size);
			root->content_size = content_size;
		}
	}
	return (root);
}
