/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:48:45 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:19:56 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

char		**ft_array_internal(void)
{
	char	**int_cmd;
	char	*cmd_int;

	int_cmd = NULL;
	cmd_int = ft_strnew(0);
	cmd_int = ft_strjoin(cmd_int, "cd,setenv,unsetenv,env,exit");
	int_cmd = ft_strsplit(cmd_int, ',');
	return (int_cmd);
}

int			test_internal(char *cmd)
{
	int		i;
	char	**int_cmd;

	int_cmd = NULL;
	int_cmd = ft_array_internal();
	i = 0;
	while (int_cmd[i] != NULL)
	{
		if (ft_strcmp(int_cmd[i], cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}

