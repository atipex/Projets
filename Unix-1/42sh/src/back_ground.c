#include <unistd.h>
#include "lib.h"
#include "42sh.h"
#include "ft_printf.h"

int		back_ground(t_cmd *cmd, t_data *data)
{
	t_cmd	*tmp;
	int		pid;

	tmp = cmd->next;
	while (tmp->next != cmd)
		tmp = tmp->next;
	if (ft_strncmp(tmp->word, "&", 1) == 1)
	{
		if ((pid = fork()) == -1)
			return (ft_error("error : fork fail\n"));
		if (pid == 0)
		{
			setpgid(getpid(), getpid());
			remove_elem(cmd->prev);
			exe_cmd(cmd, data);
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}
