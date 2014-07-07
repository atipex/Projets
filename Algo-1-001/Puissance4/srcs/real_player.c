#include <stdlib.h>
#include "ft_puissance4.h"

static int		ft_isdigitr(char *av)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (av == NULL)
		return (0);
	while (av[++i])
	{
		if (ft_isdigit(av[i]))
			count++;
	}
	if ((unsigned)count == ft_strlen(av))
		return (1);
	else
		return (0);
}

static char		*ret_get(void)
{
	char	*line;
	int		count;

	line = ft_strnew(3);
	count = 0;
	while (get_next_line(0, &line))
	{
		if (count == 0)
			break ;
	}
	return (line);
}

static int		r_x(int x)
{
	int		c;
	char	*tmp;

	c = -1;
	tmp = ft_memalloc(0);
	while (1)
	{
		ft_putstr("\nChoose where you want play : ");
		tmp = ret_get();
		if (ft_isdigitr(tmp) && ft_strlen(tmp) > 0)
		{
			c = ft_atoi(tmp);
			free(tmp);
			if (c >= 0 && c <= x)
				return (c);
		}
	}
}

int		real_player(t_tab *obj)
{
	int		gx;

	gx = r_x(obj->lines + 1);
	return (gx);
}

