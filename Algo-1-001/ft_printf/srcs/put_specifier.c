#include "ft.h"

int	put_specifier(int cnt, char *str, t_arg *args)
{
	int	mem;

	mem = is_flags(cnt, str, "cdiouxXpbSs%");
	if (mem == -1)
		args->fakespec = str[cnt];
	args->specifier = mem;
	return (cnt + 1);
}
