#include <stdlib.h>
#include "lib.h"
#include "42sh.h"

char	*search_path(char **env)
{
  int	i;

  i = 0;
  while (env[i] && !ft_strncmp(env[i], "PATH=", 5))
    i++;
  return (env[i]);
}

int	count_path(char *path)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (path[i])
    {
      if (path[i] == ':')
	nb++;
      i++;
    }
  return (nb);
}

int	ft_strlen_path(char *path)
{
  int	i;

  i = 0;
  while (path[i] && path[i] != ':')
    i++;
  return (i);
}

char	**cpy_path(char *path_line)
{
  int	i;
  int	j;
  int	k;
  char	**path;

  i = 5;
  j = 0;
  path = malloc((count_path(path_line) + 1) * sizeof(char *));
  if (path == NULL)
    return ((char **)ft_error_ptr("Fail malloc()"));
  while (path_line[i])
    {
      k = 0;
      path[j] = malloc(ft_strlen_path(path_line + i) + 2);
      if (path[j] == NULL)
	return ((char **)ft_error_ptr("Fail malloc()"));
      while (path_line[i] && path_line[i] != ':')
	path[j][k++] = path_line[i++];
      path[j][k++] = '/';
      path[j++][k] = '\0';
      if (path_line[i])
	i++;
    }
  path[j] = NULL;
  return (path);
}

char	**gimme_path(char **env)
{
  char	*path_line;

  path_line = search_path(env);
  if (!path_line)
    return ((char **)ft_error_ptr("No path"));
  return (cpy_path(path_line));
}
