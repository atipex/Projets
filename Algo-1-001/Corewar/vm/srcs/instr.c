#include <stdlib.h>
#include "corewar.h"

int		spec_func(t_chp *chp, t_charu *a)
{
	t_charu		*tmp;

	if (chp->cmd->fct == 1)
		chp->cmd->type_args[0] = 4;
	else if (chp->cmd->fct == 9)
	{
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 1, a);
		chp->cmd->type_args[0] = tmp[0];
		tmp = new_add(chp->PC + 2, a);
		chp->cmd->type_args[1] = tmp[0];
	}
	else if (chp->cmd->fct == 12 || chp->cmd->fct == 15)
	{
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 1, a);
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 2, a);
		chp->cmd->type_args[1] = 2;
	}
	else
		return (0);
	return (1);
}

void	give_i(t_chp *chp, t_charu *a)
{
	t_charu		*tmp;
	char		args_type[8];

	chp->cmd->fct = chp->PC[0];
	if (spec_func(chp, a))
		return ;
	tmp = new_add(chp->PC + 1, a);
	convert_dev(tmp[0], args_type);
	giv_args_type(chp, args_type);
	giv_args(chp, a);
}

