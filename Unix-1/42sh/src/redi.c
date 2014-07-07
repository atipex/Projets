#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42sh.h"
#include "get_next_line.h"
#include "lib.h"

int		redi_right(char *file, t_data *data)
{
  static int	fd = 0;

  (void)data;
  if (fd && fd != -1)
    close(fd);
  fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
  if (fd == -1)
    {
      ft_putstr(file, 1);
      ft_putstr(": No such file or directory.\n", 1);
      return (0);
    }
  if (dup2(fd, 1) == -1)
    return (ft_error("fail dup2"));
  return (0);
}

int		redi_d_right(char *file, t_data *data)
{
  static int	fd = 0;

  (void)data;
  if (fd && fd != -1)
    close(fd);
  fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0644);
  if (fd == -1)
    {
      ft_putstr(file, 1);
      ft_putstr(": No such file or directory.\n", 1);
      return (0);
    }
  if (dup2(fd, 1) == -1)
    return (ft_error("fail dup2"));
  return (0);
}

int		redi_left(char *file, t_data *data)
{
  static int	fd = 0;

  (void)data;
  if (fd && fd != -1)
    close(fd);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    {
      ft_putstr(file, 1);
      ft_putstr(": No such file or directory.\n", 1);
      return (-2);
    }
  if (dup2(fd, 0) == -1)
    return (ft_error("fail dup2"));
  return (0);
}

int	write_and_read_redi_d_left(char *buffer)
{
  int	i;
  int	pid;
  int	pipe_fd[2];

  i = 0;
  if (pipe(pipe_fd) == -1
      ||(pid = fork()) == -1)
    return (ft_error("fail fork / pipe"));
  if (pid)
    {
      close(pipe_fd[1]);
      if (dup2(pipe_fd[0], 0) == -1)
	return (ft_error("fail dup2"));
      return (0);
    }
  else
    {
      while (buffer[i])
	{
	  write(pipe_fd[1], buffer + i, 1);
	  i++;
	}
      return (-1);
    }
}

int	redi_d_left(char *key_word, t_data *data)
{
  int	size;
  char	*str;
  char	*buffer;

  size = SIZE_MALLOC;
  if ((buffer = malloc(size)) == NULL)
    return (ft_error("fail malloc"));
  buffer[0] = '\0';
  ft_putstr("? ", data->save_fd[1]);
  while ((str = get_next_line(0)) && !ft_strcmp(str, key_word))
    {
      while (ft_strlen(buffer) + ft_strlen(str) + 2 >= size)
	{
	  size += SIZE_MALLOC;
	  if ((buffer = ft_realloc(buffer, size)) == NULL)
	    return (-1);
	}
      if ((buffer = ft_strcat_redi(buffer, str)) == NULL
	  || (buffer = ft_strcat_redi(buffer, "\n")) == NULL)
	return (-1);
      ft_putstr("? ", data->save_fd[1]);
      free(str);
    }
  return (write_and_read_redi_d_left(buffer));
}
