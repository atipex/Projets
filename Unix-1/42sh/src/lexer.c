#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

t_identify identify_tab[] =
  {
    {REDI_D_LEFT, TYPE_D_LEFT},
    {REDI_D_RIGHT, TYPE_D_RIGHT},
    {REDI_RIGHT, TYPE_RIGHT},
    {REDI_LEFT, TYPE_LEFT},
    {AND, TYPE_AND},
    {OR, TYPE_OR},
    {CMD_SEP, TYPE_CMD_SEP},
    {PIPE, TYPE_PIPE},
    {NULL, TYPE_ARG}
  };

void	lexer(t_cmd *cmd_data)
{
  int	i;
  t_cmd	*tmp_cmd;

  tmp_cmd = cmd_data->next;
  while (tmp_cmd != cmd_data)
    {
      i = 0;
      while (identify_tab[i].name
	     && !ft_strncmp(tmp_cmd->word,
			    identify_tab[i].name,
			    ft_strlen(identify_tab[i].name)))
	i++;
      tmp_cmd->type = identify_tab[i].type;
      tmp_cmd = tmp_cmd->next;
    }
}
