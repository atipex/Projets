/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 01:27:20 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:15:33 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

void		ft_print_env(t_list *obj)
{

	while (obj->next != NULL)
	{
		ft_putstr(obj->key_word);
		ft_putchar('=');
		ft_putstr(obj->value);
		ft_putchar('\n');
		obj = obj->next;
	}
	ft_putstr(obj->key_word);
	ft_putchar('=');
	ft_putstr(obj->value);
	ft_putchar('\n');
}

