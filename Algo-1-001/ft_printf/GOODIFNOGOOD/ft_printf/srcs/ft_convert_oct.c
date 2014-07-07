#include "ft_printf.h"

int		ft_convert_oct(unsigned int nb)
{
	int		res[20];
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (nb == 0)
		ret = 1;
	while (nb != 0)
	{
		res[i++] = nb % 8;
		nb = nb / 8;
	}
	while (--i >= 0)
		ret += ft_putnbr(res[i]);
	return (ret);
}
