
#include "ft_puissance4.h"

static void	last(int j)
{
	int		i;

	i = -1;
	ft_putchar('\t');
	ft_putstr("  ");
	while (++i < j)
	{
		ft_putnbr(i);
		ft_putstr("   ");
	}
		ft_putchar('\n');
		return ;
}

void		aff_tab(char **tab)
{
	int		i;
	int		j;

	i = glob_obj(0)->lines;
	j = 0;
	while (i-- != 0)
	{
		j = 0;
		ft_putstr("\t| ");
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			ft_putstr(" | ");
			j++;
		}
		ft_putchar('\n');
	}
	last(j);
	return ;
}
