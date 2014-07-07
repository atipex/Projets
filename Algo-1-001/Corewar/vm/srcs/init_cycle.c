#include "corewar.h"
#include <stdlib.h>

t_cycle		*init_cycle(void)
{
	t_cycle		*s;

	if ((s = malloc(sizeof(*s))) == NULL)
		ft_er("Can't malloc.");
	s->nbr_live = 0;
	s->cycle_to_die = CYCLE_TO_DIE;
	s->current_cycle = 1;
	return (s);
}

