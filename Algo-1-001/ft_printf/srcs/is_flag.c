#include "ft.h"

int	is_flags(int cnt, char *str, char *val)
{
	int	c;

	c = 0;
	while (val[c])
	{
		if (val[c] == str[cnt])
			return (c);
		c += 1;
	}
	return (-1);
}
