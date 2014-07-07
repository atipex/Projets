/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:14:49 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:23:37 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "ftminishell1.h"

char		*select_path(t_list *obj, char *comm)
{
	char				**path_user;
	int					i;
	DIR					*path;
	struct dirent		*read_dir;

	i = 0;
	path_user = NULL;
	path_user = recup_path(obj);
	while (path_user[i] != NULL)
	{
		path = opendir(path_user[i]);
		while ((read_dir = readdir(path)) != NULL)
		{
			if (ft_strcmp(read_dir->d_name, comm) == 0)
				return (path_user[i]);
		}
		i++;
	}
	return (NULL);
}

void		verif_ext_com_2(t_list *obj, char **comm)
{
	char		*path;
	char		*err;
	char		*exe;

	path = ft_strnew(0);
	path = ft_strjoin(path, select_path(obj, comm[0]));
	if (path == NULL)
	{
		err = ft_strnew(0);
		err = ft_strjoin(err, comm[0]);
		err = ft_strjoin(err, ": Command not found\n");
		ft_putstr_fd(err, 2);
		exit(0);
	}
	else
	{
		exe = ft_strnew(0);
		exe = ft_strjoin(exe, path);
		exe = ft_strjoin(exe, "/");
		exe = ft_strjoin(exe, comm[0]);
		execve(exe, comm, cl_to_tab(start_obj(obj)));
		exit(0);
	}
}

void		verif_ext_com(t_list *obj, char **comm)
{
	pid_t		pid;
	int			status;

	pid = fork();
	wait(&status);
	if (pid == 0)
	{
		if ((access(comm[0], F_OK | X_OK) == 0))
		{
			execve(comm[0], comm, cl_to_tab(start_obj(obj)));
		}
		else
			verif_ext_com_2(obj, comm);
	}
}

