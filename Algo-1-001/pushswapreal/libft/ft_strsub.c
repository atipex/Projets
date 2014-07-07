#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	return (str);
}
