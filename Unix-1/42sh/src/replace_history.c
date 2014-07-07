#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "ft_printf.h"
#include "42sh.h"

int	find_by_num_reverse(t_cmd *tmp, t_his *his)
{
  char	*cpy;
  t_cmd	*replace;
  t_his	*tmp_his;
  int	num_to_search;

  tmp_his = his->prev->prev;
  num_to_search = his->prev->num - ft_getnbr(tmp->word + 2);
  while (tmp_his != his)
    {
      if (tmp_his->num == num_to_search)
	{
	  if ((cpy = ft_strdup(tmp_his->var)) == NULL
	      || (replace = gimme_cmd_data(cpy)) == NULL)
	    return (-1);
	  return (replace_cmd(tmp, tmp_his, his, replace));
	}
      tmp_his = tmp_his->prev;
    }
  ft_printf("event %d not found\n", num_to_search);
  return (-2);
}

int	find_by_num(t_cmd *tmp, t_his *his)
{
  char	*cpy;
  t_cmd	*replace;
  t_his	*tmp_his;
  int	num_to_search;

  tmp_his = his->next;
  num_to_search = ft_getnbr(tmp->word + 1);
  while (tmp_his != his->prev)
    {
      if (tmp_his->num == num_to_search)
	{
	  if ((cpy = ft_strdup(tmp_his->var)) == NULL
	      || (replace = gimme_cmd_data(cpy)) == NULL)
	    return (-1);
	  return (replace_cmd(tmp, tmp_his, his, replace));
	}
      tmp_his = tmp_his->next;
    }
  ft_printf("event %d not found\n", num_to_search);
  return (-2);
}

int	find_by_name(t_cmd *tmp, t_his *his)
{
  char	*cpy;
  t_cmd	*replace;
  t_his	*tmp_his;

  tmp_his = his->prev->prev;
  while (tmp_his != his)
    {
      if (strstr(tmp_his->var, tmp->word + 1))
	{
	  if ((cpy = ft_strdup(tmp_his->var)) == NULL
	      || (replace = gimme_cmd_data(cpy)) == NULL)
	    return (-1);
	  return (replace_cmd(tmp, tmp_his, his, replace));
	}
      tmp_his = tmp_his->prev;
    }
  ft_printf("event %s not found\n", tmp->word + 1);
  return (-2);
}

int	last_event(t_cmd *tmp, t_his *his)
{
  t_cmd	*replace;
  char	*cpy;

  if (his->prev->prev == his)
    {
      ft_printf("event %s not found\n", tmp->word + 1);
      return (-2);
    }
  if ((cpy = ft_strdup(his->prev->prev->var)) == NULL
      || (replace = gimme_cmd_data(cpy)) == NULL)
    return (-1);
  return (replace_cmd(tmp, his->prev->prev, his, replace));
}

int	replace_history(t_cmd *tmp, t_his *his)
{
  if (tmp->word[1] >= '0' && tmp->word[1] <= '9')
    return (find_by_num(tmp, his));
  else if (tmp->word[1] == '-' &&
	   tmp->word[2] >= '0' && tmp->word[2] <= '9')
    return (find_by_num_reverse(tmp, his));
  else if (tmp->word[1] == '!')
    return (last_event(tmp, his));
  else
    return (find_by_name(tmp, his));
  return (0);
}
