
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

char	*try_path(char *cmd, char **path)
{
  char	*good_path;
  int	i;

  i = 0;
  while (path && path[i] != NULL)
    {
      good_path = ft_strcat(path[i], cmd);
      if (good_path == NULL)
	return (NULL);
      if (access(good_path, X_OK) == 0)
	return (good_path);
      i++;
    }
  return (ft_strdup(cmd));
}

char	*gimme_good_path(char *cmd, t_data *data, char **env_tab)
{
  char	*new_cmd;
  char	**path_tab;

  path_tab = gimme_path(env_tab);
  if (access(cmd, X_OK) == 0)
    return (ft_strdup(cmd));
  if ((new_cmd = try_path(cmd, path_tab)) == NULL)
    return (NULL);
  if (ft_strcmp(new_cmd, cmd) == 1)
    {
      free(new_cmd);
      new_cmd = try_path(cmd, data->path);
    }
  return (new_cmd);
}

char	**env_in_tab(t_env *env)
{
  t_env	*root;
  int	i;
  char	**env_tab;

  i = 0;
  root = env;
  env = env->next;
  while (env != root)
    {
      env = env->next;
      i++;
    }
  if ((env_tab = malloc(sizeof(char *) * (i + 1))) == NULL)
    return ((char **)ft_error_ptr("fail malloc"));
  i = 0;
  env = env->next;
  while (env != root)
    {
      env_tab[i] = env->var;
      i++;
      env = env->next;
    }
  env_tab[i] = NULL;
  return (env_tab);
}

char	**cmd_in_tab(t_cmd *cmd)
{
  t_cmd	*root;
  int	i;
  char	**cmd_tab;

  i = 0;
  root = cmd;
  cmd = cmd->next;
  while (cmd != root)
    {
      cmd = cmd->next;
      i++;
    }
  if ((cmd_tab = malloc(sizeof(char *) * (i + 1))) == NULL)
    return ((char **)ft_error_ptr("fail malloc"));
  i = 0;
  cmd = cmd->next;
  while (cmd != root)
    {
      cmd_tab[i] = cmd->word;
      i++;
      cmd = cmd->next;
    }
  cmd_tab[i] = NULL;
  return (cmd_tab);
}
