#include "ft_alum.h"

static int		r_line(int *l)
{
	int		i;
	int		j;

	i = -1;
	j = 5;
	while (++i <= 4)
	{
		if (l[i] == 0)
			j--;
	}
	return (j);
}

void			start_game(int *l, int player)
{
	int		r;

	r = r_line(l);
	if (player == 1)
	{
		while (r != 0)
		{
			real_player(l);
			comp(l);
			r = r_line(l);
		}
	}
	if (player == 2)
	{
		while (r != 0)
		{
			comp(l);
			real_player(l);
			r = r_line(l);
		}
	}
}

