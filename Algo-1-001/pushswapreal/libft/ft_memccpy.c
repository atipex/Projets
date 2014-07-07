
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned char	ch;

	dst = s1;
	src = s2;
	while (n != 0)
	{
		*dst++ = ch = *src++;
		if (ch == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
