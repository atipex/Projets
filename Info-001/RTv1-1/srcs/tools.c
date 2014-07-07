/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:21:26 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:21:29 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <libft.h>

void		add_or_create_list(t_list **addto, void *toadd, int size)
{
	if (*addto == NULL)
		*addto = ft_lstnew(toadd, size);
	else
		ft_lstadd(addto, ft_lstnew(toadd, size));
}

void		trim_to_double_point(char **tmp)
{
	*tmp = &(ft_strchr(*tmp, ':'))[1];
	*tmp = ft_strtrim(*tmp);
}

int			not_double(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit && str[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int			not_int(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit)
			return (1);
		i++;
	}
	return (0);
}
