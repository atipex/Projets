#include <stdlib.h>
#include "42sh.h"
#include "ft_printf.h"

char		*ft_strndup(char *str, int n)
{
  int		i;
  char		*new_str;

  i = 0;
  new_str = malloc(n + 1);
  if (new_str == NULL)
    return (ft_error_ptr("fail malloc"));
  while (i < n && str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	*ft_realloc(char *cmd, int size)
{
  int	i;
  char	*new_cmd;

  i = 0;
  new_cmd = malloc(size);
  if (new_cmd == NULL)
    return (ft_error_ptr("Fail malloc()"));
  while (cmd[i])
    {
      new_cmd[i] = cmd[i];
      i++;
    }
  while (i < size)
    new_cmd[i++] = '\0';
  free(cmd);
  return (new_cmd);
}

char	*ft_malloc(int size)
{
  int	i;
  char	*str;

  i = 0;
  str = malloc(size);
  if (str == NULL)
    return (ft_error_ptr("Fail malloc"));
  while (i < size)
    str[i++] = '\0';
  return (str);
}

void	init_buf(char buf[3])
{
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
}

void	aff_prompt(void)
{
  ft_printf("%C$> %C", "CYAN", "WHITE");
}
