
#include "corewar.h"
#include <stdlib.h>

t_charu		*init_arena(void)
{
	int			i;
	t_charu		*arena;

	i = 0;
	if ((arena = malloc(sizeof(t_charu) * MEM_SIZE)) == NULL)
		ft_er("Can't malloc()");
	while (i < MEM_SIZE)
		arena[i++] = 0;
	return (arena);
}

t_cycle		*init_cycles(void)
{
	t_cycle		*c;

	if ((c = malloc(sizeof(*c))) == NULL)
		ft_er("Error malloc()");
	c->nbr_live = 0;
	c->cycle_to_die = CYCLE_TO_DIE;
	c->current_cycle = 1;
	return (c);
}

void		init_chp(t_chp *chp, int id)
{
	int		i;

	i = 1;
	chp->reg[0] = id;
	chp->pid = id;
	chp->f = 0;
	while (i < REG_NUMBER)
		chp->reg[i++] = 0;
	chp->cycle = 0;
	chp->cycle_to_die = 0;
	chp->carry = 0;
	chp->cmd = malloc(sizeof(*(chp->cmd)));
	chp->parsing->cont = malloc(MEM_SIZE);
	if (chp->cmd == NULL || chp->parsing->cont == NULL)
		ft_er("Error on malloc()");
	chp->cmd->type_args[0] = 0;
	chp->cmd->type_args[1] = 0;
	chp->cmd->type_args[2] = 0;
}

t_chp		*mchp(int argc, char **argv, t_charu *a)
{
	t_chp	*t;

	t = root();
	data_chp_d(argc, argv, t);
	ins_chp(t, a);
	return (t);
}
