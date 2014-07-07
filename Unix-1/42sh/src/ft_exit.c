#include <unistd.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

int	ft_exit(t_cmd *cmd, t_data *data)
{
  (void)data;
  g_exit_value = (cmd->next->next != cmd ? ft_getnbr(cmd->next->next->word)
		  : 0);
  ft_printf("Exit (%d)\n", g_exit_value);
  return (-1);
}
