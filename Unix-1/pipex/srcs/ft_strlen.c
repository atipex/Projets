#include <string.h>

size_t			ft_strlen(const char *str)
{
	unsigned int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
