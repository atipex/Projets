#include <unistd.h>
#include "42sh.h"

void		pipe_exit(t_tree *tree, t_param *param)
{
  static int	exit_value = 1;

  exit_value = exit_value ? g_last_exit : 0;
  if (param == tree->param->prev)
    {
      g_last_exit = exit_value;
      exit_value = 1;
    }
}

int	start_pipe(int pipe_fd[2][2], int *k, t_data *data)
{
  *k = 1;
  data->pipe = 1;
  if (pipe(pipe_fd[0]) == -1
      || dup2(pipe_fd[0][1], 1) == -1)
    return (ft_error("fail pipe / dup2"));
  return (1);
}

int	end_pipe(int pipe_fd[2][2], int *k, t_data *data)
{
  data->pipe = 0;
  if (*k == 1)
    {
      if (dup2(pipe_fd[0][0], 0) == -1)
	return (ft_error("fail dup2"));
      close(pipe_fd[0][1]);
      if (pipe_fd[1][0] != -1)
	close(pipe_fd[1][0]);
    }
  else
    {
      if (dup2(pipe_fd[1][0], 0) == -1)
	return (ft_error("fail dup2"));
      close(pipe_fd[1][1]);
      close(pipe_fd[0][0]);
    }
  *k *= -1;
  return (1);
}

int	mid_pipe(int pipe_fd[2][2], int *k, t_data *data)
{
  data->pipe = 1;
  if (*k == 1)
    {
      if (pipe_fd[1][0] != -1)
	close(pipe_fd[1][0]);
      if (pipe(pipe_fd[1]) == -1
	  || dup2(pipe_fd[1][1], 1) == -1
	  || dup2(pipe_fd[0][0], 0) == -1)
	return (ft_error("fail pipe / dup"));
      close(pipe_fd[0][1]);
    }
  else
    {
      close(pipe_fd[0][0]);
      if (pipe(pipe_fd[0]) == -1
	  || dup2(pipe_fd[0][1], 1) == -1
	  || dup2(pipe_fd[1][0], 0) == -1)
	return (ft_error("fail pipe / dup"));
      close(pipe_fd[1][1]);
    }
  *k *= -1;
  return (1);
}
