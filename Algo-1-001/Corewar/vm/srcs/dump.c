
#include <stdlib.h>
#include "corewar.h"

void	conv_b(int nbr, int base)
{
	int		mod;

	mod = nbr % base;
	nbr /= base;
	if (nbr)
		conv_b(nbr, base);
	if (mod > 9)
		ft_putchar('A' + (mod % 10));
	else
		ft_putnbr(mod);
}

void	new_l(int i, int *line)
{
	ft_putchar('\n');
	if (i < MEM_SIZE)
	{
		conv_b(*line, 16);
		ft_putstr("\t: ");
		*(line) += 1;
	}
}

void	d_mem(t_chp *chp, t_cycle *c, t_charu *a)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	conv_b(line++, 16);
	ft_putstr("\t: ");
	while (i < MEM_SIZE)
	{
		if (a[i] < 17)
			ft_putchar('0');
		conv_b((int)a[i], 16);
		i++;
		if (i % 16 == 0)
			new_l(i, &line);
		else if (i < MEM_SIZE)
			ft_putchar(' ');
	}
	clean(chp, c, a);
}

