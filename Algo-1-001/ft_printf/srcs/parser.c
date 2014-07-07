#include <stdarg.h>
#include <stdlib.h>
#include "ft.h"

int	parser(char *str, va_list ap)
{
	int	cnt;
	t_arg	*args;
	t_arg *tmp;
	int	res;

	cnt = 0;
	args = NULL;
	res = 0;
	(void)args;
	while (str[cnt])
	{
		if (str[cnt] == '%')
		{
			tmp = malloc(sizeof(*tmp));
			cnt = put_flags(cnt + 1, str, tmp);
			cnt = put_width(cnt, str, tmp);
			cnt = put_precision(cnt, str, tmp);
			cnt = put_specifier(cnt, str, tmp);
			res += print_flags(tmp, ap);
			res += print_spec(tmp, ap);
		}
		ft_putchar(str[cnt]);
		cnt += 1;
	}
	return (res);
}
