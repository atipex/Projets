
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*strnew;

	if ((strnew = (char *)malloc((size + 1) * sizeof(*strnew))) == NULL)
		return (NULL);
	while (size != 0)
	{
		strnew[size] = '\0';
		size--;
	}
	strnew[size] = '\0';
	return (strnew);
}
