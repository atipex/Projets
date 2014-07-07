
#include "ft_puissance4.h"
#include <time.h>
#include <stdlib.h>

static int		ft_player(void)
{
	int		t;

	t = time(0);
	srand(t);
	if (rand() % 2 == 0)
		return (1);
	return (0);
}

void		welcome(t_tab *obj)
{
	int		play;

	play = 0;
	play = ft_player();
	ft_putendl("\n\t\t\033[034mWelcome to Puissance 4!");
	ft_putstr("\nRules:");
	ft_putendl("\n\t- Align 4 chips to win.");
	ft_putstr("\t- ");
	ft_putchar(PLAYER);
	ft_putendl(" : player chip.");
	ft_putstr("\t- ");
	ft_putchar(IA);
	ft_putendl(" : CPU chip.");
	ft_putstr("\t- There is ");
	ft_putnbr(obj->count_max);
	ft_putendl("  chip.\033[0m\n");
	ft_putstr("First player is ");
	if (!play)
		ft_putendl("YOU");
	else
		ft_putendl("COMPUTER");
	ft_putendl("MAY THE FORCE BE WITH YOU !\n\n");
	glob_obj(0)->player = play;
	return ;
}
