#include <stdarg.h>
#include "ft.h"

int	print_flags(t_arg *args, va_list ap)
{
	int	res;

	res = 0;
	(void)ap;
	if (args)
	{
		while (args->flags)
		{
			if (args->flags->data == 2)
				res += print_spaces(args);
			args->flags = args->flags->next;
		}
	}
	return (res);
}
