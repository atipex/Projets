
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*strdup;

	i = -1;
	len = ft_strlen(s1) + 1;
	if ((strdup = ft_strnew(len)) == NULL)
		return (NULL);
	while (++i < len)
		strdup[i] = s1[i];
	return (strdup);
}
