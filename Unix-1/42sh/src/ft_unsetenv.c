#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

int		remove_var(char *var_name, t_env *env)
{
  t_env		*tmp;
  char		*tmp_var;

  tmp_var = var_name;
  tmp = env->next;
  var_name = ft_strcat(var_name, "=");
  if (var_name == NULL)
    return (-1);
  while (tmp != env)
    {
      if (ft_strncmp(var_name, tmp->var, ft_strlen(var_name)))
	{
	  tmp->prev->next = tmp->next;
	  tmp->next->prev = tmp->prev;
	  free(tmp->var);
	  free(tmp);
	  free(var_name);
	  return (1);
	}
      tmp = tmp->next;
    }
  ft_printf("error : %s : is not a var.\n", tmp_var);
  return (0);
}

int		option_star(t_data *data)
{
  t_env		*elem;
  char		*str_cpy;
  int		i;

  elem = data->env->next;
  while (elem != data->env)
    {
      i = 0;
      while (elem->var[i] && elem->var[i] != '=')
	++i;
      if ((str_cpy = ft_strndup(elem->var, i)) == NULL)
	return (-1);
      elem = elem->next;
      if (remove_var(str_cpy, data->env) == -1)
	return (-1);
      free(str_cpy);
    }
  return (0);
}

int		ft_unsetenv(t_cmd *cmd, t_data *data)
{
  t_cmd		*root;

  root = cmd;
  cmd = cmd->next->next;
  if (cmd == root)
    {
      ft_printf("unsetenv: Too few arguments\n");
      return (9);
    }
  if (ft_strcmp(cmd->word, "*") == 1)
    {
      if ((option_star(data)) == -1)
	return (-1);
    }
  else
    {
      while (cmd != root)
	{
	  if (remove_var(cmd->word, data->env) == -1)
	    return (-1);
	  cmd = cmd->next;
	}
    }
  return (1);
}
