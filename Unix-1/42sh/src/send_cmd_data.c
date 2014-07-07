#include <stdlib.h>
#include "42sh.h"
#include "command.h"

t_cmd	*init_cmd_data(void)
{
 t_cmd	*cmd_data;

  cmd_data = malloc(sizeof(t_cmd));
  if (cmd_data == NULL)
    return ((t_cmd *)ft_error_ptr("Fail malloc"));
  cmd_data->next = cmd_data;
  cmd_data->prev = cmd_data;
  return (cmd_data);
}

t_cmd	*add_to_list(t_cmd *cmd_data, char *word)
{
  t_cmd	*new_elem;

  new_elem = malloc(sizeof(t_cmd));
  if (new_elem == NULL)
    return ((t_cmd *)ft_error_ptr("Fail malloc"));
  new_elem->word = word;
  new_elem->type = 0;
  new_elem->next = cmd_data;
  new_elem->prev = cmd_data->prev;
  cmd_data->prev->next = new_elem;
  cmd_data->prev = new_elem;
  return (new_elem);
}

t_cmd	*gimme_cmd_data(char *command)
{
  t_cmd	*cmd_data;

  if ((cmd_data = init_cmd_data()) == NULL
      || str_to_linked_list(command, cmd_data) == NULL)
    return (NULL);
  return (cmd_data);
}
