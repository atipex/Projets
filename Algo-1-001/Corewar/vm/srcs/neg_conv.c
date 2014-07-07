
#include "corewar.h"

int		neg_conve_int(t_charu *args, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += (255 - args[i++]) * ft_pow(256, exp--);
	return ((sum + 1) * -1);
}

int		neg_conve_int_instr(t_charu *args, int size, t_charu *a)
{
	int			i;
	int			exp;
	int			sum;
	t_charu		*tmp;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
	{
		tmp = new_add(args + i++, a);
		sum += (255 - tmp[0]) * ft_pow(256, exp--);
	}
	return ((sum + 1) * -1);
}
