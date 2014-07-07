#include <stdlib.h>
#include "pipex.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*cpy;

	dst = (char *)malloc(sizeof(dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst && s1 && s2)
	{
		cpy = dst;
		while (*s1 != '\0')
			*dst++ = *s1++;
		while (*s2 != '\0')
			*dst++ = *s2++;
		*dst = '\0';
	}
	else
		return (NULL);
	return (cpy);
}
