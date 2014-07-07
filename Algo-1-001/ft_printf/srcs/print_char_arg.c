#include <stdarg.h>
#include "ft.h"

int	print_char_arg(int nbr, va_list ap)
{
	int	res;

	res = 0;
	if (nbr == 10)
		res += ft_putstr(va_arg(ap, char *));
	else if (nbr == 9)
		res += ft_putallstr(va_arg(ap, char *));
	return (res);
}
