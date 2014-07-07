#include <stdlib.h>
#include "corewar.h"

void	convert_dev(int nbr, char *args_type)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		args_type[i--] = nbr % 2;
		nbr /= 2;
	}
}

void	giv_args_type(t_chp *chp, char *args_type)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (args_type[i] || args_type[i + 1])
		{
			if (args_type[i] && args_type[i + 1])
				chp->cmd->type_args[i / 2] = IND_SIZE;
			else if (args_type[i])
				chp->cmd->type_args[i / 2] = DIR_SIZE;
			else if (args_type[i + 1])
				chp->cmd->type_args[i / 2] = T_REG;
			else
				chp->cmd->type_args[i / 2] = 0;
		}
		i += 2;
	}
}

void	giv_args(t_chp *chp, t_charu *a)
{
	int			i;
	int			size;
	t_charu		*tmp;

	size = chp->cmd->type_args[0] + chp->cmd->type_args[1];
	size += chp->cmd->type_args[2];
	i = -1;
	while (++i < size)
	{
		tmp = new_add(chp->PC + 2 + i, a);
		chp->cmd->args[i] = tmp[0];
	}
}

