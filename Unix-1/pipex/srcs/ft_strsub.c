#include <stdlib.h>
#include "pipex.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(s1) * (len + 1));
	if (s1 && s)
	{
		s2 = s1;
		while (start-- > 0)
			s++;
		while (len-- > 0)
			*s1++ = *s++;
		*s1 = '\0';
	}
	else
		return (NULL);
	return (s2);
}
