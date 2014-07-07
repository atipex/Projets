#include <stdlib.h>
#include "lib.h"
#include "42sh.h"
#include "ft_printf.h"

void	aff_var(t_var *var)
{
  t_var	*tmp;

  tmp = var->next;
  while (tmp != var)
    {
      ft_printf("%s\t%s\n", tmp->var, tmp->content);
      tmp = tmp->next;
    }
}

int	update_var(t_cmd *tmp, t_var *exist)
{
  int	i;

  i = 0;
  while (tmp->word[i] && tmp->word[i] != '=')
    ++i;
  if (tmp->word[i])
    ++i;
  free(exist->content);
  exist->content = ft_strdup(tmp->word + i);
  if (exist->content == NULL)
    return (-1);
  return (0);
}

int	create_var(t_cmd *tmp, t_var *var)
{
  int	i;

  i = 0;
  while (tmp->word[i] && tmp->word[i] != '=')
    ++i;
  if (tmp->word[i])
    {
      tmp->word[i] = '\0';
      ++i;
    }
  if (put_in_list(var, tmp->word) == NULL
      || (var->prev->content = ft_strdup(tmp->word + i)) == NULL)
    return (-1);
  return (0);
}

int	ft_set(t_cmd *cmd, t_data *data)
{
  t_cmd	*tmp;
  t_var	*exist;

  tmp = cmd->next->next;
  while (tmp != cmd)
    {
      if (verif_var(tmp))
	{
	  if ((exist = already_exist_var(tmp, data->var))
	      && update_var(tmp, exist) == -1)
	    return (-1);
	  else if (!exist)
	    if (create_var(tmp, data->var) == -1)
	      return (-1);
	}
      else
	{
	  ft_putstr("Var should begin with a letter\n", 2);
	  return (0);
	}
      tmp = tmp->next;
    }
  if (cmd->next->next == cmd)
    aff_var(data->var);
  return (1);
}
