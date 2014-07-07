
#include <stdio.h>
#include "corewar.h"

void	aff(t_charu *a, t_chp *chp)
{
	int		i;

	i = giv_para_val(chp, chp->cmd, 0, a);
	if (chp->cmd->type_args[0] == 1)
	i = chp->reg[giv_reg_nbr(i)];
	i = i % 256;
	i = ABS(i);
	ft_putnbr(i);
}

int		exec_live(t_chp *tmp, t_chp *chp)
{
	if (tmp->pid == chp->reg[0])
	{
		if (!tmp->f)
		{
			ft_putstr("Le joueur ");
			ft_putnbr(tmp->pid);
			ft_putstr("(");
			ft_putstr(tmp->name);
			ft_putendl(") est en vie");
			g_winner_id = tmp->pid;
			g_winner_name = tmp->name;
		}
		tmp->cycle_to_die = 0;
		return (1);
	}
	return (0);
}

