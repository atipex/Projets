#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*save;

	i = -1;
	save = s;
	while (++i < n)
		save[i] = '\0';
}
