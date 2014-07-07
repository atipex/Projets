#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

int	replace_cmd(t_cmd *tmp, t_his *tmp_his, t_his *his, t_cmd *replace)
{
  tmp->prev->next = replace->next;
  tmp->next->prev = replace->prev;
  replace->next->prev = tmp->prev;
  replace->prev->next = tmp->next;
  tmp = replace->next;
  free(replace);
  if ((his->prev->var = ft_strdup(tmp_his->var)) == NULL)
    return (-1);
  return (0);
}

int	find_and_replace_var(t_cmd *tmp, t_var *var, int len)
{
  t_var	*tmp_var;

  tmp_var = var->next;
  while (tmp_var != var)
    {
      if (ft_strncmp(tmp->word + 1, tmp_var->var, len))
	{
	  tmp->word = ft_strdup(tmp_var->content);
	  if (tmp->word == NULL)
	    return (ft_error_parse("fail strdup"));
	  return (0);
	}
      tmp_var = tmp_var->next;
    }
  return (-2);
}

int	find_and_replace(t_cmd *tmp, t_env *env, t_var *var)
{
  int	ret;
  int	len;
  t_env	*tmp_env;

  len = ft_strlen(tmp->word + 1);
  tmp_env = env->next;
  while (tmp_env != env)
    {
      if (ft_strncmp(tmp->word + 1, tmp_env->var, len))
	{
	  tmp->word = ft_strdup(tmp_env->var + len + 1);
	  if (tmp->word == NULL)
	    return (ft_error_parse("fail strdup"));
	  return (0);
	}
      tmp_env = tmp_env->next;
    }
  if ((ret = find_and_replace_var(tmp, var, len)) == -1 || ret == 0)
    return (ret);
  ft_error_parse("Wrong variable name.");
  return (-2);
}

int	replace_tild(t_cmd *tmp, t_env *env, char *home)
{
  char	*tmp_home;

  if ((tmp_home = gimme_home(env)))
    {
      if ((tmp_home = ft_strdup(tmp_home)) == NULL)
	return (ft_error("fail strdup"));
    }
  else if (home)
    tmp_home = home;
  else
    return (0);
  if (tmp->word[1] == '/')
    tmp->word = tmp->word + 1;
  else
    tmp->word[0] = '/';
  if ((tmp->word = ft_strcat(tmp_home, tmp->word)) == NULL)
    return (ft_error("fail strcat"));
  return (0);
}

int	replace_var(t_cmd *cmd, t_data *data)
{
  int	ret;
  t_cmd	*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      if (tmp->word[0] == '!')
	if ((ret = replace_history(tmp, data->his)) == -1 || ret == -2)
	  return (ret);
      if (tmp->word[0] == '$')
	if ((ret = find_and_replace(tmp, data->env, data->var)) == -1
	    || ret == -2)
	  return (ret);
      if (tmp->word[0] == '~')
	if (replace_tild(tmp, data->env, data->home) == -1)
	  return (-1);
      tmp = tmp->next;
    }
  return (0);
}
