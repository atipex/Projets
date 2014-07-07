#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "pipex.h"

void		pipex3(int *pfda, int *pfd, t_struct obj, char **env)
{
	int		pfdb[2];
	int		pid;
	int		fd;

	if ((fd = open(obj.file2[0], O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		err_cmd(obj.file2[0], "Can't open file: ");
	if (pipe(pfdb) == -1)
		_exit(1);
	if ((pid = fork()) < 0)
		_exit(1);
	if (pid > 0)
	{
		close(pfd[1]);
		close(pfd[0]);
		close(pfda[1]);
		close(pfdb[0]);
		dup2(pfda[0], 0);
		dup2(fd, 1);
		execve(obj.cmd2[0], obj.cmd2, env);
	}
	else
		close(fd);
}

void		pipex2(int *pfd, t_struct obj, char **env)
{
	int		pfda[2];
	int		pid;

	if (pipe(pfda) == -1)
		_exit(1);
	if ((pid = fork()) < 0)
		_exit(1);
	if (pid == 0)
	{
		close(pfd[1]);
		close(pfda[0]);
		dup2(pfd[0], 0);
		dup2(pfda[1], 1);
		close(pfd[0]);
		close(pfd[1]);
		execve(obj.cmd1[0], obj.cmd1, env);
	}
	else
		pipex3(pfda, pfd, obj, env);
}

void		pipex(t_struct obj, char **env)
{
	int		pfd[2];
	int		pid;
	char	*str;

	str = ft_strnew(0);
	str = ft_strjoin(str, where_is_the_cat(env));
	if (pipe(pfd) == -1)
		_exit(1);
	if ((pid = fork()) < 0)
		_exit(1);
	if (pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve(str, obj.file1, env);
	}
	else
		pipex2(pfd, obj, env);
}
