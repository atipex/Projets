#include "ft_alum.h"

static void	show_m(int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_putstr("\033[031m|\033[0m");
	ft_putchar('\n');
}

void		show_game(int *l)
{
	ft_putstr("\n1) (");
	ft_putnbr(l[0]);
	ft_putstr(")	    ");
	show_m(l[0]);
	ft_putstr("2) (");
	ft_putnbr(l[1]);
	ft_putstr(")	   ");
	show_m(l[1]);
	ft_putstr("3) (");
	ft_putnbr(l[2]);
	ft_putstr(")	  ");
	show_m(l[2]);
	ft_putstr("4) (");
	ft_putnbr(l[3]);
	ft_putstr(")	 ");
	show_m(l[3]);
	ft_putstr("5) (");
	ft_putnbr(l[4]);
	ft_putstr(")	");
	show_m(l[4]);
}

