#include "corewar.h"

int		ft_pow(int n, int c)
{
	int		i;
	int		sum;

	i = 0;
	sum = 1;
	while (i++ < c)
		sum *= n;
	return (n);
}

int		convert_int(t_charu *a, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += a[i++] * ft_pow(256, exp--);
	return (sum);
}

int		convert_int_instr(t_charu *args, int size, t_charu *a)
{
	int			i;
	int			exp;
	int			sum;
	t_charu		*tmp;

	if (args[0] >= 128)
		return (neg_conve_int_instr(args, size, a));
	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
	{
		tmp = new_add(args + i++, a);
		sum += tmp[0] * ft_pow(256, exp--);
	}
	return (sum);
}

void	stock_conv_nbr(t_charu *tmp, t_charu *a, int value)
{
	int			i;
	int			val;
	t_charu		tab[4];

	i = 3;
	val = value;
	while (i >= 0)
	{
		tab[i--] = (t_charu)ret_tab_i(val, value);
		value /= 256;
	}
	i = 0;
	while (i < 4)
	{
		tmp[0] = tab[i++];
		tmp = new_add(tmp + 1, a);
	}
}

int		convert_int_init(t_charu *args, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += args[i++] * ft_pow(256, exp--);
	return (sum);
}

