
#include <stdio.h>
#include "corewar.h"

void		and(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		i = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i & j) ? 0 : 1;
	chp->reg[k] = i & j;
}

void		or(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i | j) ? 0 : 1;
	chp->reg[k] = i | j;
}

void		xor(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i ^ j) ? 0 : 1;
	chp->reg[k] = i ^ j;
}

void		zjmp(t_charu *a, t_chp *chp)
{
	int		sum;

	if (chp->carry == 0)
		return ;
	sum = convert_int(chp->cmd->args, chp->cmd->type_args[0]);
	chp->PC = new_add(chp->PC + sum, a);
}

void		ldi(t_charu *a, t_chp *chp)
{
	int			i;
	int			j;
	int			k;
	int			val;
	t_charu		*tmp;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	tmp = chp->PC + i % IDX_MOD;
	tmp = new_add(tmp, a);
	val = convert_int_instr(tmp, IND_SIZE, a) + j;
	tmp = chp->PC + val % IDX_MOD;
	tmp = new_add(tmp, a);
	k = giv_reg_nbr(k);
	val = convert_int_instr(tmp, REG_SIZE, a);
	chp->carry = val ? 0 : 1;
	chp->reg[k] = val;
}

