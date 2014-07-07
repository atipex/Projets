#include <stdlib.h>
#include "lib.h"
#include "42sh.h"
#include "ft_printf.h"

void	aff_history(t_data *data)
{
  t_his	*tmp;

  tmp = data->his->next;
  while (tmp != data->his)
    {
      ft_printf("%d\t%s\n", tmp->num, tmp->var);
      tmp = tmp->next;
    }
}

void	history_dash_c(t_data *data)
{
  t_his	*tmp;

  tmp = data->his->next;
  while (tmp != data->his)
    {
      tmp = tmp->next;
      free(tmp->prev->var);
      free(tmp->prev);
    }
  tmp->pos = 1;
  tmp->next = tmp;
  tmp->prev = tmp;
}

int	ft_history(t_cmd *cmd, t_data *data)
{
  if (cmd->next->next != cmd &&
      ft_strcmp(cmd->next->next->word, "-c"))
    history_dash_c(data);
  else
    aff_history(data);
  return (1);
}
