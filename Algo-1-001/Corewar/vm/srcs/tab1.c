
#include "corewar.h"
#include <stdio.h>

void		live(t_charu *a, t_chp *chp)
{
	t_chp	*tmp;

	tmp = chp;
	(void) a;
	if (exec_live(tmp, chp))
		return ;
	tmp = tmp->nxt;
	while (tmp != chp)
	{
		if (exec_live(tmp, chp))
			return ;
		tmp = tmp->nxt;
	}
}

void		ld(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	j = giv_reg_nbr(j);
	chp->carry = i ? 0 : 1;
	chp->reg[j] = i;
}

void		st(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		chp->reg[giv_reg_nbr(j)] = i;
	else if (chp->cmd->type_args[1] == 2)
	{
		j = convert_int(chp->cmd->args + chp->cmd->type_args[0], 2);
		stock_conv_nbr(chp->PC+ j, a, i);
	}
}

void		add_(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i + j) ? 0 : 1;
	chp->reg[k] = i + j;
}

void		sub(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i - j) ? 0 : 1;
	chp->reg[k] = i - j;
}

