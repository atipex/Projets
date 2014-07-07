#include <unistd.h>
#include "pipex.h"

char			*where_is_the_cat(char **env)
{
	char		*str;
	int			i;
	char		**path;

	i = 0;
	path = NULL;
	while ((ft_strncmp(env[i], "PATH=", 5)) != 0 && env[i] != NULL)
		i++;
	if (env[i] == NULL)
		no_path();
	else
		path = ft_strsplit(ft_strsub(env[i], 5, (ft_strlen(env[i]) - 4)), ':');
	i = -1;
	while (i++, path[i] != NULL)
	{
		str = ft_strnew(0);
		str = ft_strjoin(str, path[i]);
		str = ft_strjoin(str, "/");
		str = ft_strjoin(str, "cat");
		if (access(str, F_OK) == 0)
			return (str);
	}
	err_cmd("cat", "Command not found: ");
	return (NULL);
}
