
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)malloc(size * sizeof(*ptr))) == NULL)
		return (NULL);
	while (size != 0)
	{
		ptr[size] = '\0';
		size--;
	}
	ptr[size] = '\0';
	return (ptr);
}
