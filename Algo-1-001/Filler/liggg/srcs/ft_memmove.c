
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dst;
	char		*save;

	i = -1;
	if ((save = (char *)malloc(sizeof(ft_strlen(s1)))) == NULL)
		return (NULL);
	dst = s1;
	ft_memcpy(save, s2, n);
	while (++i < n)
		dst[i] = save[i];
	free (save);
	return (dst);
}
