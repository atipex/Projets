
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*save;
	size_t		i;

	i = ft_strlen(s2);
	save = s1;
	if (i == 0)
		return ((char *)s1);
	while (*save && save + i <= s1 + n)
	{
		if (*save == *s2 && ft_strncmp(save + 1, s2 + 1, i - 1) == 0)
			return ((char *)save);
		save++;
	}
	return (NULL);
}
