#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

int	init_term(char **env)
{
  int	i;
  int	ret;

  i = 0;
  while (env[i] && !ft_strncmp(env[i], "TERM=", 5))
    i++;
  if (!env[i])
    return (ft_error("No term var"));
  ret = tgetent(NULL, env[i] + 5);
  if (ret == 0 || ret == -1)
    return (ft_error("Fail tegetent()"));
  return (0);
}

char	*gimme_pwd(char **env)
{
  int	i;

  i = 0;
  while (env[i] && !ft_strncmp("PWD=", env[i], 4))
    i++;
  if (env[i] == NULL)
    return (NULL);
  else
    return (env[i] + 4);
}

int	save_fd(t_data *data)
{
  if ((data->save_fd[0] = dup(0)) == -1
      || (data->save_fd[1] = dup(1)) == -1)
    return (ft_error("fail dup"));
  return (0);
}

t_data		*init(char **env, t_bool *tty)
{
  t_data	*data;

  if ((data = malloc(sizeof(t_data))) == NULL)
    return ((t_data *)ft_error_ptr("Fail malloc"));
  if (*tty)
    if (init_term(env) == -1)
      *tty = 0;
  if (save_fd(data) == -1
      || (data->env = gimme_env(env)) == NULL
      || (data->his = gimme_root()) == NULL
      || (data->var = gimme_root()) == NULL)
    return (NULL);
  data->pwd = gimme_pwd(env);
  data->path = gimme_path(env);
  data->alias = NULL;
  data->home = gimme_home(data->env);
  data->old_pwd = NULL;
  return (data);
}
