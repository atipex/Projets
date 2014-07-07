#include "ft_alum.h"
#include <stdlib.h>

static char	*ret_get(void)
{
	char	*line;
	int		count;

	line = ft_strnew(0);
	count = 0;
	while (get_next_line(0, &line))
	{
		count++;
		if (count == 1)
			break ;
	}
	return (line);
}

static int	r_line(int *l)
{
	int		i;
	int		j;

	i = -1;
	j = 5;
	while (++ i<= 4)
	{
		if (l[i] == 0)
			j--;
	}
	return (j);
}

int			match(int *l, int c)
{
	int		nb;
	int		r;

	nb = 0;
	r = r_line(l);
	while (1)
	{
		ft_putstr("How many ? ");
		nb = ft_atoi(ret_get());
		if (r == 1 && l[nb] == 1)
		{
			ft_putendl("\n\033[036mYou LOSE\033[0m");
			exit(0);
		}
		if (nb > 0 && nb <= l[c])
		{
			l[c] = l[c] - nb;
			show_game(l);
			if (r_line(l) == 0)
				ft_putendl("\n\033[036mYou LOSE\033[0m");
			return (EXIT_SUCCESS);
		}
	}
}

