#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

t_alias		*put_alias_in_list(t_alias *alias, char *name, char *cmd)
{
  t_alias	*ellem;

  if ((ellem = malloc(sizeof(*ellem))) == NULL
      || (ellem->name = ft_strdup(name)) == NULL
      || (ellem->cmd = ft_strdup(cmd)) == NULL)
    return (ft_error_ptr("fail malloc / strdup"));
  ellem->next = alias;
  return (ellem);
}

int		find_word(char *word, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (ft_strncmp(word, str + i, ft_strlen(word)) == 1)
	{
	  str += i + ft_strlen(word);
	  if (*str == '\0' || *str == ' ')
	    return (1);
	}
      i++;
    }
  return (0);
}

void		check_loop(t_alias *name, t_alias *cmd, t_alias **root)
{
  while (name != NULL)
    {
      cmd = *root;
      while (cmd != NULL)
	{
	  if (find_word(name->name, cmd->cmd) == 1)
	    {
	      ft_putstr("error : alias can loop\n", 2);
	      put_alias_off_list(root, cmd);
	    }
	  cmd = cmd->next;
	}
      name = name->next;
    }
}

int		ft_alias(t_cmd *cmd, t_data *data)
{
  int		i;
  t_alias	*tmp;

  tmp = data->alias;
  i = gimme_nb_arg(cmd);
  if (i == 1)
    {
      while (tmp)
	{
	  ft_printf("%s\t%s\n", tmp->name, tmp->cmd);
	  tmp = tmp->next;
	}
      return (1);
    }
  else if (i != 3)
    {
      ft_putstr("error : alias : bad arg number.\n", 2);
      return (0);
    }
  cmd = cmd->next;
  if ((data->alias = put_alias_in_list(data->alias, cmd->next->word,
				       cmd->next->next->word)) == NULL)
    return (-1);
  check_loop(data->alias, data->alias, &data->alias);
  return (1);
}
