#include "ft_printf.h"

static int		ft_intlen(unsigned int n)
{
	int	ilen;

	if (n == 0)
		ilen = 1;
	else
		ilen = ft_strlen(ft_itoa_unsint(n));
	return (ilen);
}

static void		ft_process_nbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_process_nbr(n / 10);
		ft_process_nbr(n % 10);
	}
	else
		ft_putchar(48 + n);
}

int				ft_putuint(unsigned int n)
{
	int		ret;

	ret = ft_intlen(n);
	ft_process_nbr(n);
	return (ret);
}
