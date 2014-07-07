
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (f != NULL && s != NULL)
	{
		while (*s)
		{
			f(i, s);
			s++;
			i++;
		}
	}
}
