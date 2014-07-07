#include <unistd.h>
#include "42sh.h"

int	and_exec(t_tree *tree, t_param *param, t_data *data)
{
  (void)tree;
  (void)param;
  (void)data;
  return (g_last_exit ? 1 : 0);
}

int	or_exec(t_tree *tree, t_param *param, t_data *data)
{
  (void)tree;
  (void)param;
  (void)data;
  return (g_last_exit ? 0 : 1);
}

int		pipe_exec(t_tree *tree, t_param *param, t_data *data)
{
  static int	i = 0;
  static int	k = 1;
  static int	pipe_fd[2][2];

  if (param == tree->param->next)
    {
      if (i == 0)
	i++;
      else
	{
	  if (k == -1)
	    close(pipe_fd[0][0]);
	  else if (pipe_fd[1][0] != -1)
	    close(pipe_fd[1][0]);
	}
      pipe_fd[1][0] = -1;
      return (start_pipe(pipe_fd, &k, data));
    }
  else if (param == tree->param->prev)
    return (end_pipe(pipe_fd, &k, data));
  else
    return (mid_pipe(pipe_fd, &k, data));
}
