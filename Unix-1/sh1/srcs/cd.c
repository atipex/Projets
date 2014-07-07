/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:37:26 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 17:19:15 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "ftminishell1.h"

t_list		*ft_cd_change(t_list *obj, char *cmd)
{
	char		*swap;
	char		direc[1024];

	obj = search_in_obj(start_obj(obj), "PWD");
	swap =ft_strnew(0);
	swap = ft_strjoin(swap, obj->value);
	obj->value = cmd;
	obj = search_in_obj(start_obj(obj), "OLDPWD");
	obj->value = swap;
	chdir(cmd);
	getcwd(direc, sizeof(direc));
	swap = ft_strnew(0);
	swap = ft_strjoin(swap, pure_wd(direc));
	obj = search_in_obj(start_obj(obj), "PWD");
	obj->value = swap;
	return (obj);
}

t_list		*ft_cd_is_good(struct stat sb, t_list *obj, char *cmd)
{
	char	*msg;

	msg = ft_strnew(0);
	if (sb.st_mode & S_IFDIR)
	{
		if (access(cmd, R_OK) == 0 || access(cmd, X_OK) == 0)
		{
			obj = ft_cd_change(obj, cmd);
			return (obj);
		}
		else
			ft_putstr_fd("cd: permission denied\n", 2);
	}
	else
	{
		msg = ft_strjoin(msg, "cd: not a directory: ");
		msg = ft_strjoin(msg, cmd);
		msg = ft_strjoin(msg, "\n");
		ft_putstr_fd(msg, 2);
	}
	return (obj);
}

t_list		*ft_cd_dir(t_list *obj, char *cmd)
{
	struct stat		sb;
	char			*msg;
	char			*comm;

	msg = ft_strnew(0);
	comm = ft_strnew(0);
	comm = ft_strjoin(comm, check_tilde(cmd, obj));
	if (stat(comm, &sb) == -1)
	{
		msg = ft_strjoin(msg, "cd: no such file or directory: ");
		msg = ft_strjoin(msg, comm);
		msg = ft_strjoin(msg, "\n");
		ft_putstr_fd(msg, 2);
	}
	else
		obj = ft_cd_is_good(sb, obj, comm);
	return (obj);
}

t_list		*ft_cd_home(t_list *obj, char *dest)
{
	char		*swap;
	char		*swap2;

	obj = search_in_obj(obj, dest);
	swap = ft_strnew(0);
	swap = ft_strjoin(swap, obj->value);
	obj = search_in_obj(start_obj(obj), "PWD");
	swap2 =ft_strnew(0);
	swap2 = ft_strjoin(swap2, obj->value);
	obj->value = swap;
	obj = search_in_obj(start_obj(obj), "OLDPWD");
	obj->value = swap2;
	chdir(swap);
	return (obj);
}

t_list		*ft_cd(t_list *obj, char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 1)
		obj = ft_cd_home(obj, "HOME");
	else if (i == 2)
	{
		if (ft_strcmp(cmd[1], "~") == 0)
			obj = ft_cd_home(obj, "HOME");
		else if (ft_strcmp(cmd[1], "-") == 0)
			obj = ft_cd_reverse(obj);
		else
			obj = ft_cd_dir(obj, cmd[1]);
	}
	else
		ft_putstr_fd("cd: too many arguments\n", 2);
	return (obj);
}

