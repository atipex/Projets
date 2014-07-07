
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
