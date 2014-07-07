#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (size > 0)
	{
		s[i] = '\0';
		i++;
		size--;
	}
	s[i] = '\0';
	return (s);
}
