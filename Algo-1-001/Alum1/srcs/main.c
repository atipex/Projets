#include <stdlib.h>
#include "ft_alum.h"

static void	launch(int *l)
{
	int		player;

	player = 0;
	ft_putendl("\n\t\033[034mWelcome to the Allum1!\033[0m");
	show_game(l);
	ft_putchar('\n');
	player = ft_player();
	start_game(l, player);
}

int			main(void)
{
	int		*l;

	l = ft_memalloc(5);
	l[0] = 1;
	l[1] = 3;
	l[2] = 5;
	l[3] = 7;
	l[4] = 9;
	launch(l);
	free(l);
	return (0);
}

