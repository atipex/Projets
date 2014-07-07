#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

int	father_exec(int pid, t_data *data)
{
  int	status;
  char	*ret;

  if (data->pipe == 0)
    waitpid(pid, &status, 0);
  if (data->pipe == 0 && WIFEXITED(status) == 0)
    {
      ret = strsignal(WTERMSIG(status));
      if (ret == NULL)
	return (-1);
      ft_printf("%s\n", ret);
      g_last_exit = 0;
    }
  else
    g_last_exit = 1;
  return (0);
}

int	exec_path(char **cmd_tab, char **env_tab, t_data *data)
{
  int	pid;

  if (access(cmd_tab[0], X_OK) == -1)
    {
      ft_printf("error : \"%s\" command not found.\n", cmd_tab[0]);
      g_last_exit = 0;
      return (0);
    }
  if ((pid = fork()) == -1)
    return (ft_error("error : fork fail\n"));
  if (pid == 0)
    {
      execve(cmd_tab[0], cmd_tab, env_tab);
      return (-1);
    }
  else
    return (father_exec(pid, data));
}

int	ft_exec(t_cmd *cmd, t_data *data)
{
  char	**env_tab;
  char	**cmd_tab;
  char	*path;

  if ((env_tab = env_in_tab(data->env)) == NULL)
    return (-1);
  if ((path = gimme_good_path(cmd->next->word, data, env_tab)) == NULL)
    return (-1);
  cmd->next->word = path;
  if ((cmd_tab = cmd_in_tab(cmd)) == NULL)
    return (-1);
  return (exec_path(cmd_tab, env_tab, data));
}
