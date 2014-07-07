#include <stdlib.h>
#include "42sh.h"
#include "ft_printf.h"
#include "lib.h"

t_env		*find_var(t_env *env, char *var)
{
  t_env		*root;

  root = env;
  env = env->next;
  while (root != env)
    {
      if (ft_strncmp(var, env->var, ft_strlen(var)) == 1)
	return (env);
      env = env->next;
    }
  return (root);
}

int		add_to_env(t_cmd *cmd, t_env *env)
{
  t_env		*var_env;
  t_cmd		*root;
  char		*var_name;
  char		*var_full;

  root = cmd;
  root->word = "";
  cmd = cmd->next->next;
  if ((var_name = ft_strcat(cmd->word, "=")) == NULL
      || (var_env = find_var(env, var_name)) == NULL
      || (var_full = ft_strcat(var_name, cmd->next->word)) == NULL)
    return (-1);
  free(var_name);
  if (var_env == env)
    put_in_list(env, var_full);
  else
    {
      free(var_env->var);
      var_env->var = var_full;
    }
  return (1);
}

int		add_to_env_glob(t_cmd *cmd, t_env *env)
{
  t_env		*var_env;
  t_cmd		*root;
  char		*var_name;
  char		*var_full;
  char		*var_glob;

  root = cmd;
  root->word = "";
  cmd = cmd->next->next;
  if ((var_name = ft_strcat(cmd->word, "=")) == NULL
      || (var_env = find_var(env, var_name)) == NULL
      || (var_glob = globing_for_setenv(cmd)) == NULL
      || (var_full = ft_strcat(var_name, var_glob)) == NULL)
    return (-1);
  free(var_name);
  if (var_env == env)
    put_in_list(env, var_full);
  else
    {
      free(var_env->var);
      var_env->var = var_full;
    }
  return (1);
}

int		ft_setenv(t_cmd *cmd, t_data *data)
{
  int		i;

  i = gimme_nb_arg(cmd);
  if (i > 3)
    {
      ft_putstr("error : setenv : too many argument.\n", 1);
      return (0);
    }
  if (i == 1)
    return (ft_env(cmd, data));
  else if (i == 3 && is_there_a_star(cmd->next->next->next->word))
    return (add_to_env_glob(cmd, data->env));
  return (add_to_env(cmd, data->env));
}
