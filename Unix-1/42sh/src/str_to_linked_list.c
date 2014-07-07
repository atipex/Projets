#include "42sh.h"

int	manage_space_and_tab(char *str, int i)
{
  str[i] = '\0';
  i++;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  return (i);
}

int	manage_double_quote(char *str, t_cmd *cmd, int i)
{
  str[i] = '\0';
  ++i;
  add_to_list(cmd, str + i);
  while (str[i] != '\0' && str[i] != '"')
    ++i;
  if (str[i] == '\0')
    return (i);
  str[i] = '\0';
  ++i;
  return (i);
}

int	manage_other(char *str, t_cmd *cmd, int i)
{
  add_to_list(cmd, str + i);
  while (str[i] != '\0'
	 && str[i] != ' '
	 && str[i] != '"'
	 && str[i] != '\t'
	 && str[i] != '\'')
    ++i;
  return (i);
}

int	manage_quote(char *str, t_cmd *cmd, int i)
{
  str[i] = '\0';
  ++i;
  add_to_list(cmd, str + i);
  while (str[i] != '\0' && str[i] != '\'')
    ++i;
  if (str[i] == '\0')
    return (i);
  str[i] = '\0';
  ++i;
  return (i);
}

t_cmd	*str_to_linked_list(char *str, t_cmd *cmd)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	i = manage_space_and_tab(str, i);
      else if (str[i] == '"')
	i = manage_double_quote(str, cmd, i);
      else if (str[i] == '\'')
	i = manage_quote(str, cmd, i);
      else if (str[i] != ' '
	       && str[i] != '\t'
	       && str[i] != '"'
	       && str[i] != '\'')
	i = manage_other(str, cmd, i);
    }
  return (cmd);
}
