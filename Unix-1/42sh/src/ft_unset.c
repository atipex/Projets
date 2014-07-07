#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

t_var	*already_exist_var(t_cmd *tmp, t_var *var)
{
  int	i;
  t_var	*tmp_var;

  i = 0;
  while (tmp->word[i] && tmp->word[i] != '=')
    ++i;
  tmp_var = var->next;
  while (tmp_var != var)
    {
      if (ft_strncmp(tmp->word, tmp_var->var, i))
	return (tmp_var);
      tmp_var = tmp_var->next;
    }
  return (NULL);
}

void	remove_var_builtin(t_var *exist)
{
  free(exist->content);
  free(exist->var);
  exist->prev->next = exist->next;
  exist->next->prev = exist->prev;
  free(exist);
}

int	ft_unset(t_cmd *cmd, t_data *data)
{
  t_cmd	*tmp;
  t_var	*exist;

  tmp = cmd->next->next;
  while (tmp != cmd)
    {
      if ((exist = already_exist_var(tmp, data->var)))
	remove_var_builtin(exist);
      tmp = tmp->next;
    }
  return (1);
}
