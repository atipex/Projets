#include "ft_alum.h"

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

static int	r_choice(int *l)
{
	int	c;

	c = 1;
	while (1)
	{
		ft_putstr("\n Choose your line : ");
		c = ft_atoi(ret_get());
		if (c > 0 && c < 6 && l[c - 1] != 0)
			return (c - 1);
	}
}

void		real_player(int *l)
{
	int	l_c;

	l_c = r_choice(l);
	match(l, l_c);
}

