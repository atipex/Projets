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

int			ft_player(void)
{
	int		player;

	player = 0;
	while (1)
	{
		ft_putendl("Do you want to be the first player?");
		ft_putstr("Yes(1), No(2): ");
		player = ft_atoi(ret_get());
		if (player == 1 || player == 2)
			return (player);
	}
}

