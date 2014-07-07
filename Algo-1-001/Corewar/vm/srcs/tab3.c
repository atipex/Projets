
#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

void		sti(t_charu *a, t_chp *chp)
{
	int			i;
	int			j;
	int			k;
	t_charu		*tmp;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	if (chp->cmd->type_args[2] == 1)
		k = chp->reg[giv_reg_nbr(k)];
	tmp = chp->PC + (j + k) % IDX_MOD;
	tmp = new_add(tmp, a);
	stock_conv_nbr(tmp, a, i);
}

void		fork_(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = -1;
	if (chp->f > 0)
		return ;
	j = convert_int(chp->cmd->args, 2) % IDX_MOD;
	add(chp);
	chp->prev->PC = new_add(chp->PC + j, a);
	chp->prev->reg[0] = g_pid;
	chp->prev->pid = g_pid++;
	while (++i < REG_NUMBER)
		chp->prev->reg[i] = chp->reg[i];
	chp->prev->cycle = 0;
	chp->prev->carry = chp->carry;
	chp->prev->f = chp->pid;
	chp->prev->cycle_to_die = chp->cycle_to_die;
	chp->prev->cmd = malloc(sizeof(*(chp->prev->cmd)));
	if (chp->prev->cmd == NULL)
		ft_er("Malloc() Fail");
	chp->prev->cmd->type_args[0] = 0;
	chp->prev->cmd->type_args[1] = 0;
	chp->prev->cmd->type_args[2] = 0;
}

void		lld(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	j = giv_para_val(chp, chp->cmd, 2, a);
	chp->carry = i ? 0 : 1;
	chp->reg[j] = i;
}

void		lldi(t_charu *a, t_chp *chp)
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
	tmp = chp->PC + i;
	tmp = new_add(tmp, a);
	val = convert_int_instr(tmp, IND_SIZE, a) + j;
	tmp = chp->PC + val;
	tmp = new_add(tmp, a);
	k = giv_reg_nbr(k);
	val = convert_int_instr(tmp, REG_SIZE, a);
	chp->carry = val ? 0 : 1;
	chp->reg[k] = val;
}

void		lfork(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = 1;
	j = convert_int(chp->cmd->args, 2);
	chp->carry = j ? 0 : 1;
	add(chp);
	chp->prev->PC = new_add(chp->PC + j, a);
	chp->prev->reg[0] = g_pid;
	chp->prev->pid = g_pid++;
	while (i < REG_NUMBER)
	{
		chp->prev->reg[i] = chp->reg[i];
		i++;
	}
	chp->prev->cycle = 0;
	chp->prev->carry = chp->carry;
	chp->prev->f = chp->pid;
	chp->prev->cycle_to_die = chp->cycle_to_die;
	chp->prev->cmd = malloc(sizeof(*(chp->prev->cmd)));
	if (chp->prev->cmd == NULL)
		ft_er("Malloc() fail");
	chp->prev->cmd->type_args[0] = 0;
	chp->prev->cmd->type_args[1] = 0;
	chp->prev->cmd->type_args[2] = 0;
}

