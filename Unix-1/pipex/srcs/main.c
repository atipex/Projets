#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"

void			no_path(void)
{
	ft_putendl_fd("No variables PATH in env", 2);
	_exit(1);
}

void			fill_and_check(char **av, char **env)
{
	t_struct	obj;
	char		**path;
	int			i;

	i = 0;
	path = NULL;
	init_fill_obj(&obj, av);
	check_file1(obj.file1);
	creat_tab_1(&obj);
	while ((ft_strncmp(env[i], "PATH=", 5)) != 0 && env[i] != NULL)
		i++;
	if (env[i] == NULL)
		no_path();
	else
		path = ft_strsplit(ft_strsub(env[i], 5, (ft_strlen(env[i]) - 4)), ':');
	check_cmd1(&obj, path);
	check_cmd2(&obj, path);
	check_file2(obj.file2);
	pipex(obj, env);
}

int				main(int ac, char **av, char **env)
{
	if (ac == 5 && av && env)
		fill_and_check(av, env);
	else
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
	return (0);
}
