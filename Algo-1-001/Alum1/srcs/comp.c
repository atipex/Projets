#include "ft_alum.h"
#include <stdlib.h>

static int	r_line(int *l)
{
	int	i;
	int	j;

	i = -1;
	j = 5;
	while (++i <= 4)
	{
		if (l[i] == 0)
			j--;
	}
	return (j);
}

static int	rmv(int *l, int n)
{
	l[n] = 1;
	show_game(l);
	return (EXIT_SUCCESS);
}

static int	comp_(int *l, int r, int i)
{
	while (i < 5)
	{
		if (l[i] != 0 && r >= 2)
		{
			del(l, i);
			return (EXIT_SUCCESS);
		}
		if (l[i] > 1)
		{
			rmv(l, i);
			return (EXIT_SUCCESS);
		}
		if (r == 1)
		{
			if (l[i] == 1)
			{
				del(l, i);
				ft_putendl("\n\033[036mYou WIN !\033[0m");
				exit(0);
			}
		}
		i++;
	}
	return (0);
}

static void	ia(int *l)
{
	int	i;
	int	r;

	i = 0;
	r = r_line(l);
	comp_(l, r, i);
}

void		comp(int *l)
{
	int	r;

	r = r_line(l);
	if (r == 0)
		exit(0);
	ft_putendl("\nComputer played:");
	if (r == 5)
		del(l, 0);
	if (r < 5)
		ia(l);
}
