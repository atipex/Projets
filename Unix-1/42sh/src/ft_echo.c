#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

void	check_option(t_cmd *tmp)
{
  int	i;

  i = 0;
  while (tmp->word[i])
    if (tmp->word[i] == '*')
      {
	globing_for_echo(tmp);
	return ;
      }
    else
      ++i;
  ft_printf("%s", tmp->word);
}

int	ft_echo(t_cmd *cmd, t_data *data)
{
  t_cmd	*tmp;
  int	option;

  (void)data;
  tmp = cmd->next->next;
  option = 1;
  while (tmp != cmd)
    {
      if (tmp == cmd->next->next && ft_strcmp(tmp->word, "-n") == 1)
	{
	  option = 0;
	  tmp = tmp->next;
	}
      if (tmp != cmd)
	{
	  check_option(tmp);
	  if (tmp->next != cmd && !ft_strcmp(tmp->word, "-n"))
	    ft_printf(" ");
	  tmp = tmp->next;
	}
    }
  if (option)
    ft_printf("\n");
  return (1);
}
