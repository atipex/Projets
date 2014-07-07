#include "lib.h"
#include "42sh.h"

void		put_alias_off_list(t_alias **alias, t_alias *focus)
{
  t_alias	*tmp;

  if (*alias == focus)
    {
      *alias = alias[0]->next;
      return ;
    }
  tmp = *alias;
  while (tmp->next != focus)
    tmp = tmp->next;
  tmp->next = focus->next;
}

int		ft_unalias(t_cmd *cmd, t_data *data)
{
  t_cmd		*tmp;
  t_alias	*tmp_alias;

  tmp = cmd->next->next;
  if (tmp == cmd)
    {
      ft_putstr("No parameters.\n", 2);
      return (0);
    }
  while (tmp != cmd)
    {
      tmp_alias = data->alias;
      while (tmp_alias)
	{
	  if (ft_strcmp(tmp->word, tmp_alias->name))
	    put_alias_off_list(&data->alias, tmp_alias);
	  tmp_alias = tmp_alias->next;
	}
      tmp = tmp->next;
    }
  return (1);
}
