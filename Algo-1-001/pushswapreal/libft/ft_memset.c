
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*save;

	i = -1;
	save = b;
	while (++i < len)
		save[i] = c;
	return (b);
}
