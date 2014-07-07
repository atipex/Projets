#include <stdlib.h>
#include "ft.h"
char	*cpy_str(char *src, int s, int e)
{
	char	*cpy;
	int	cnt;
	int	str_cnt;

	cpy = malloc(sizeof(char) * (e - s));
	if (cpy == NULL)
		return (NULL);
	cnt = 0;
	str_cnt = s;
	while (cnt <= (e - s))
	{
		cpy[cnt] = src[str_cnt];
		cnt += 1;
		str_cnt += 1;
	}
	cpy[cnt] = '\0';
	return (cpy);
}
