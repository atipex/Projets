#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

void	aff_nicely(t_his *tmp, char **cmd, int *i)
{
  int	j;

  j = 0;
  ft_putstr(tgetstr("cb", NULL), 1);
  ft_putstr(tgetstr("ce", NULL), 1);
  ft_putstr(tgoto(tgetstr("ch", NULL), 1, 0), 1);
  aff_prompt();
  if (tmp->var)
    while (tmp->var[j])
      {
	(*cmd)[j] = tmp->var[j];
	j++;
      }
  while (j < g_prompt.size)
    (*cmd)[j++] = '\0';
  ft_putstr(*cmd, 1);
  *i = ft_strlen(*cmd) + 1;
}

void	history_prompt(char buf[3], int *i, char **cmd, t_data *data)
{
  t_his	*tmp;

  tmp = data->his;
  while (tmp->pos == -1)
    tmp = tmp->next;
  tmp->pos *= -1;
  if (buf[2] == UP)
    tmp = tmp->prev;
  else if (buf[2] == DOWN)
    tmp = tmp->next;
  tmp->pos *= -1;
  aff_nicely(tmp, cmd, i);
}
