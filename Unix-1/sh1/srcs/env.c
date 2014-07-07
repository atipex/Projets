/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 03:59:29 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:21:27 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

t_list		*ft_env(t_list *obj, char **cmd)
{
	char	**cpy_env;
	int		i;

	i = 0;
	cpy_env = cl_to_tab(obj);
	while (cmd[i] != NULL)
		i++;
	if (i == 1)
		ft_print_tmp_env(cpy_env);
	else
		ft_putendl_fd("Too many arguments", 2);
	return (obj);
}

