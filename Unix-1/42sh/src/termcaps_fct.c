#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "lib.h"
#include "42sh.h"

int	check_arrow(char buf[3], char **cmd, int *i, t_data *data)
{
  if (buf[2] == LEFT)
    {
      if (*i > 1)
	{
	  ft_putstr("\b", 1);
	  *i -= 1;
	}
    }
  else if (buf[2] == RIGHT)
    {
      if (*i <= ft_strlen(*cmd))
	{
	  ft_putstr(tgetstr("nd", NULL), 1);
	  *i += 1;
	}
    }
  else if (buf[2] == DOWN || buf[2] == UP)
    history_prompt(buf, i, cmd, data);
  return (0);
}

int	ctrl_termcaps(char buf[3], char **cmd, int *i, t_data *data)
{
  (void)i;
  (void)data;
  if (buf[0] == CTRLD)
    {
      ft_putchar('\n');
      return (-1);
    }
  else if (buf[0] == CTRLL)
    {
      ft_putstr(tgetstr("cl", NULL), 1);
      aff_prompt();
      ft_putstr(*cmd, 1);
    }
  return (0);
}

int	add_char(char buf[3], char **cmd, int *i, t_data *data)
{
  (void)data;
  (*cmd)[*i - 1] = buf[0];
  *i += 1;
  ft_putchar(buf[0]);
  return (0);
}

int	backspace_termcaps(char buf[3], char **cmd, int *i, t_data *data)
{
  (void)buf;
  (void)data;
  if (*i > 1)
    {
      ft_putstr("\b \b", 1);
      *i -=1;
      (*cmd)[*i - 1] = (*cmd)[*i] ? ' ' : '\0';
    }
  return (0);
}
