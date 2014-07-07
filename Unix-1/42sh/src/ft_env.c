#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

int		ft_env(t_cmd *cmd, t_data *data)
{
  t_env		*tmp;

  (void)cmd;
  tmp = data->env->next;
  while (tmp != data->env)
    {
      ft_putstr(tmp->var, 1);
      ft_putchar('\n');
      tmp = tmp->next;
    }
  return (1);
}
