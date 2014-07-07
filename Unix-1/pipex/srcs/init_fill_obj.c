#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"

void				check_file1(char **file1)
{
	struct stat		sb;

	if (access(file1[0], F_OK) != 0)
		err_cmd(file1[0], "No such file or directory: ");
	if (access(file1[0], R_OK) != 0)
		err_cmd(file1[0], "Permission Denied: ");
	stat(file1[0], &sb);
	if (sb.st_mode & S_IFDIR)
		err_cmd(file1[0], "Is not a file: ");
}

void				check_cmd1(t_struct *obj, char **path)
{
	char			*str;
	int				i;

	str = ft_strnew(0);
	str = ft_strjoin(str, obj->cmd1[0]);
	i = -1;
	while (i++, path[i] != NULL)
	{
		if ((ft_strncmp(obj->cmd1[0], "/", 1) != 0)
			&& (ft_strncmp(obj->cmd1[0], ".", 1) != 0))
		{
			str = ft_strnew(0);
			str = ft_strjoin(str, path[i]);
			str = ft_strjoin(str, "/");
			str = ft_strjoin(str, obj->cmd1[0]);
		}
		if (access(str, F_OK) == 0)
		{
			obj->cmd1[0] = str;
			return ;
		}
	}
	err_cmd(obj->cmd1[0], "Command not found: ");
}

void				check_cmd2(t_struct *obj, char **path)
{
	char			*str;
	int				i;

	str = ft_strnew(0);
	str = ft_strjoin(str, obj->cmd2[0]);
	i = -1;
	while (i++, path[i] != NULL)
	{
		if ((ft_strncmp(obj->cmd2[0], "/", 1) != 0)
			&& (ft_strncmp(obj->cmd2[0], ".", 1) != 0))
		{
			str = ft_strnew(0);
			str = ft_strjoin(str, path[i]);
			str = ft_strjoin(str, "/");
			str = ft_strjoin(str, obj->cmd2[0]);
		}
		if (access(str, F_OK) == 0)
		{
			obj->cmd2[0] = str;
			return ;
		}
	}
	err_cmd(obj->cmd2[0], "Command not found: ");
}

void				check_file2(char **file2)
{
	struct stat		sb;

	if (access(file2[0], F_OK) == 0)
	{
		if (access(file2[0], W_OK) != 0)
			err_cmd(file2[0], "Destination file read-only: ");
		stat(file2[0], &sb);
		if (sb.st_mode & S_IFDIR)
		{
			err_cmd(file2[0], "Is not file: ");
			_exit(1);
		}
	}
}

void				init_fill_obj(t_struct *obj, char **av)
{
	char			**cmd11;
	char			**cmd21;
	char			**file11;
	char			**file21;

	file11 = NULL;
	file21 = NULL;
	file11 = ft_strsplit(av[1], ' ');
	file21 = ft_strsplit(av[4], ' ');
	obj->file1 = file11;
	obj->file2 = file21;
	cmd11 = NULL;
	cmd21 = NULL;
	cmd11 = ft_strsplit(av[2], ' ');
	cmd21 = ft_strsplit(av[3], ' ');
	obj->cmd1 = cmd11;
	obj->cmd2 = cmd21;
}
