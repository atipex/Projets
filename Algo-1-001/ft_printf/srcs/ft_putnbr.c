#include "ft.h"

int	ft_putnbr(int nb)
{
	int	div;
	int	res;

	div = 1;
	res = 0;
	if (nb < 0)
	{
		res += ft_putchar('-');
		if (nb > -2147483648)
			nb *= -1;
		else
		{
			nb = 147483648;
			res += ft_putchar('2');
		}
	}
	while (nb / div >= 10)
		div *= 10;
	while (div)
	{
		res += ft_putchar(nb / div % 10 + '0');
		div /= 10;
	}
	return (res);
}
