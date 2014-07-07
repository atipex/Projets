#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

t_char	char_fct[] =
  {
    {ARROW, check_arrow},
    {CTRLD, ctrl_termcaps},
    {CTRLL, ctrl_termcaps},
    {BACKSPACE, backspace_termcaps},
    {TAB, auto_completation},
    {-1, add_char}
  };

int	check_cmd(char buf[3], char **cmd, int *i, t_data *data)
{
  int	j;

  j = 0;
  while (char_fct[j].value != -1 && buf[0] != char_fct[j].value)
    j++;
  return (char_fct[j].fct_ptr(buf, cmd, i, data));
}

int	check_for_realloc(char **cmd, int size)
{
  if (ft_strlen(*cmd) + 2 >= size)
    {
      if (((*cmd) = ft_realloc(*cmd, size + SIZE_MALLOC)) == NULL)
	return (ft_error("Fail malloc"));
      size += 1024;
    }
  return (size);
}

char	*termcaps_prompt(t_data *data)
{
  int	ret;
  char	buf[3];

  g_prompt.size = 1024;
  g_prompt.i = 1;
  if ((g_prompt.cmd = ft_malloc(SIZE_MALLOC)) == NULL)
    return (NULL);
  init_buf(buf);
  while ((ret = read(0, buf, 3) > 0))
    {
      if ((g_prompt.size = check_for_realloc(&(g_prompt.cmd),
					   g_prompt.size)) == -1)
	return (NULL);
      if (buf[0] == '\n')
	return (g_prompt.cmd);
      else
	if (check_cmd(buf, &(g_prompt.cmd), &(g_prompt.i), data) == -1)
	  return (NULL);
      init_buf(buf);
    }
  if (ret == -1)
    return (ft_error_ptr("fail read"));
  g_prompt.cmd[0] = '\0';
  return (g_prompt.cmd);
}
