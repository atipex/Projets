
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	i = -1;
	dst = s1;
	src = s2;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}
