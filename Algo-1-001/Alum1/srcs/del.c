#include "ft_alum.h"
#include <stdlib.h>

int		del(int *l, int n)
{
	l[n] = 0;
	show_game(l);
	return (EXIT_SUCCESS);
}

