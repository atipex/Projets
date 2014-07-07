#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "42sh.h"
#include "builtin.h"
#include "ft_printf.h"

void	gere_signal(int sig)
{
  int	i;

  i = 0;
  if (g_tty)
    {
      g_prompt.i = 1;
      while (i < g_prompt.size)
	g_prompt.cmd[i++] = '\0';
    }
  (void)sig;
  ft_putchar('\n');
  aff_prompt();
}

int	create_and_exec(char *command, t_data *data)
{
  int		ret;
  t_cmd		*cmd_data;
  t_tree	*cmd_tree;

  g_tty = 0;
  if ((command = add_some_space(command)) == NULL
      || (cmd_data = gimme_cmd_data(command)) == NULL)
    return (-1);
  lexer(cmd_data);
  if ((ret = replace_var(cmd_data, data)) != -1
      && ret != -2 && parser(cmd_data))
    {
      if ((cmd_tree = gimme_tree(cmd_data)) == NULL
	  || exec_tree(cmd_tree, data) == -1)
	return (-1);
      free_tree(cmd_tree);
      free_command(command, cmd_data);
    }
  return (ret);
}

int		ftsh(t_data *data, t_bool tty)
{
  char		*command;

  signal(SIGINT, gere_signal);
  while ((command = gimme_command(data, tty)))
    if ((tty && exit_raw_mode() == -1)
	|| create_and_exec(command, data) == -1)
      return (-1);
  return (g_exit_value);
}

int		main(int ac, char **av, char **env)
{
  t_bool	tty;
  t_data	*data;

  (void)ac;
  (void)av;
  setsid();
  ft_printf("%CWelcome into 42sh!%C\n", "CYAN", "WHITE");
  g_exit_value = 0;
  tty = isatty(0);
  g_tty = tty;
  if ((data = init(env, &tty)) == NULL)
    return (-1);
  ftsh(data, tty);
  free_data(data);
  return (g_exit_value);
}
