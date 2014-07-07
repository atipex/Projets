#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

int	new_env_pwd(t_data *data, char *path)
{
  t_env	*tmp;

  tmp = data->env->next;
  while (tmp != data->env)
    {
      if (ft_strncmp(tmp->var, "PWD=", 4))
	{
	  tmp->var = ft_strcat("PWD=", path);
	  if (tmp->var == NULL)
	    return (-1);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (1);
}

int	cd_home(t_data	*data)
{
  if (data->home == NULL)
    return (0);
  if (chdir(data->home) == -1)
    ft_putstr("cd: Could not access home directory.\n", 2);
  else
    {
      data->old_pwd = data->pwd;
      data->pwd = data->home;
      return (new_env_pwd(data, data->home));
    }
  return (0);
}

int	cd_path(t_cmd *cmd, t_data *data)
{
  char	*path;

  path = globing_for_cd(cmd);
  if (path == NULL)
    return (0);
  if (chdir(path) == -1)
    ft_putstr("cd: Could not access directory.\n", 2);
  else
    {
      if (path[0] != '/')
	{
	  if ((path = ft_strcat("/", path)) == NULL
	      || (path = ft_strcat(data->pwd, path)) == NULL)
	    return (-1);
	}
      data->old_pwd = data->pwd;
      data->pwd = path;
      return (new_env_pwd(data, path));
    }
  return (0);
}

int	dash_cd(t_data *data)
{
  if (data->old_pwd && chdir(data->old_pwd) != -1)
    {
      swap_char(&data->old_pwd, &data->pwd);
      return (new_env_pwd(data, data->pwd));
    }
  else
    ft_putstr("cd: Could not access previous directory.\n", 2);
  return (0);
}

int	ft_cd(t_cmd *cmd, t_data *data)
{
  int	i;

  i = gimme_nb_arg(cmd);
  cmd = cmd->next;
  data->home = gimme_home(data->env);
  if (i == 1)
    return (cd_home(data));
  if (i > 2)
    ft_putstr("cd: Too many arguments.\n", 2);
  else if (ft_strncmp(cmd->next->word, "-", 1) == 1)
    return (dash_cd(data));
  else
    return (cd_path(cmd, data));
  return (0);
}
