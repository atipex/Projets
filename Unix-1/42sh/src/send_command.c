#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "42sh.h"
#include "get_next_line.h"

int	exit_raw_mode(void)
{
  struct termios	s_term;

  if (tcgetattr(0, &s_term) == -1)
    return (ft_error("Fail Tcgetattr()"));
  s_term.c_lflag = (ICANON | ECHO | ECHOCTL | ISIG);
  if (tcsetattr(0, 0, &s_term) == -1)
    return (ft_error("Fail tcsetattr()"));
  return (0);
}

int			raw_mode(void)
{
  struct termios	s_term;

  if (tcgetattr(0, &s_term) == -1)
    return (ft_error("Fail tcgetattr()"));
  s_term.c_lflag &= ~ICANON;
  s_term.c_lflag &= ~ECHO;
  s_term.c_cc[VMIN] = 1;
  s_term.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &s_term) == -1)
    return (ft_error("Fail tcsetattr()"));
  return (0);
}

t_env	*add_to_history(t_data *data, char *command)
{
  return (put_in_list(data->his, command));
}

void	reset_pos(t_data *data)
{
  t_his	*tmp;

  tmp = data->his->next;
  while (tmp != data->his)
    {
      tmp->pos = -1;
      tmp = tmp->next;
    }
  data->his->pos = 1;
}

char	*gimme_command(t_data *data, t_bool tty)
{
  char	*command;

  g_tty = tty;
  g_last_exit = 1;
  if (dup2(data->save_fd[0], 0) == -1
      || dup2(data->save_fd[1], 1) == -1)
    return (ft_error_ptr("Fail dup2"));
  aff_prompt();
  if (tty)
    {
      if (raw_mode() == -1
	  || (command = termcaps_prompt(data)) == NULL)
	return (NULL);
      reset_pos(data);
      ft_putchar('\n');
    }
  else
    command = get_next_line(0);
  if (command == NULL
      || add_to_history(data, command) == NULL)
    return (NULL);
  return (command);
}
