#include "corewar.h"

t_tab		funct_tab[] =
{
	{10, live},
	{5, ld},
	{5, st},
	{10, add_},
	{10, sub},
	{6, and},
	{6, or},
	{6, xor},
	{20, zjmp},
	{25, ldi},
	{25, sti},
	{800, fork_},
	{10, lld},
	{50, lldi},
	{1000, lfork},
	{2, aff},
};

int		check_r(t_chp *chp, t_cycle *c)
{
	int		i;
	t_chp	*tmp;

	i = 0;
	tmp = chp->nxt;
	if (c->cycle_to_die <= 0)
		return (0);
	while (tmp != chp)
	{
		if (tmp->cycle_to_die < c->cycle_to_die)
		{
			if (!tmp->f)
				i++;
			tmp = tmp->nxt;
		}
		else
		{
			del_m_f(chp, tmp);
			tmp = chp->nxt;
			i = 0;
		}
	}
	return (i);
}

void	check_cy(t_chp *chp, t_charu *a, t_cycle *c)
{
	if (chp->cycle == 0)
		check_i(chp, a);
	else if (--chp->cycle == 1)
	{
		exec_i(chp, a, c);
		chp->cycle = 0;
	}
}

void	check_i(t_chp *chp, t_charu *a)
{
	if (*chp->PC > 0 && *chp->PC < 17)
	{
		chp->cycle = funct_tab[*chp->PC - 1].cycle;
		give_i(chp, a);
	}
	else
		chp->PC = new_add(chp->PC + 1, a);
}

void	exec_i(t_chp *chp, t_charu *a, t_cycle *c)
{
	int		args;

	if (spec_func(chp, a))
		args = 1;
	else
		args = 2;
	args += chp->cmd->type_args[0];
	args += chp->cmd->type_args[1];
	args += chp->cmd->type_args[2];
	funct_tab[chp->cmd->fct - 1].fct(a, chp);
	chp->cmd->type_args[0] = 0;
	chp->cmd->type_args[1] = 0;
	chp->cmd->type_args[2] = 0;
	if (chp->cmd->fct == 9 && chp->carry)
		return ;
	else if (chp->cmd->fct == 1)
		c->nbr_live++;
	chp->PC = new_add(chp->PC + args, a);
}

