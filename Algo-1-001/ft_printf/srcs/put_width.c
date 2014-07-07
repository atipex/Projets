#include "ft.h"
int	put_width(int cnt, char *str, t_arg *args)
{
	int	start;

	start = cnt;
	while (ft_char_isnum(str[cnt]) == 1)
		cnt += 1;
	if (start != cnt)
		args->width = ft_getnbr(cpy_str(str, start, cnt));
	else
		args->width = 0;
	return (cnt);
}
