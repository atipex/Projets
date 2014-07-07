/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:55:48 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:21:52 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

t_list		*verif_b_in_cmd(t_list *obj, char **split_cmd)
{

	if (ft_strcmp(split_cmd[0], "setenv") == 0)
		obj = ft_setenv(obj, split_cmd);
	else if (ft_strcmp(split_cmd[0], "unsetenv") == 0)
		obj = ft_unsetenv(start_obj(obj), split_cmd);
	else if (ft_strcmp(split_cmd[0], "cd") == 0)
		obj = ft_cd(start_obj(obj), split_cmd);
	else if (ft_strcmp(split_cmd[0], "env") == 0)
		obj = ft_env(start_obj(obj), split_cmd);
	else if (ft_strcmp(split_cmd[0], "exit") == 0)
		ft_exit(split_cmd);
	return (obj);
}

