#include <stdarg.h>
#include "ft.h"

int    	print_spec(t_arg *args, va_list ap)
{
	int	res;

	res = 0;
	if (args->specifier >= 0 && args->specifier <= 8)
		res += print_nbr_arg(args->specifier, ap);
	else if (args->specifier >= 9 && args->specifier <= 10)
		res += print_char_arg(args->specifier, ap);
	else if (args->specifier == 11)
	{
		res += ft_putchar('%');
		if (args->next)
			args = args->next;
	}
	else
	{
		res += ft_putchar('%');
		res += ft_putchar(args->fakespec);
	}
	return (res);
}
