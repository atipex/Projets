#include "ft.h"

int	nbr_tobase(int n, char *base, char *supplement)
{
	int	len;
	int	div;
	int	res;

	len = ft_strlen(base);
	div = 1;
	res = 0;
	if (supplement)
		res += ft_putstr(supplement);
	while (len <= n / div)
		div *= len;
	while (div)
	{
		res += ft_putchar(base[n / div % len]);
		div /= len;
	}
	return (res);
}
