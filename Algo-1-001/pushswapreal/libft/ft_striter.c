
#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	if (f != NULL && s != NULL)
	{
		while (*s)
		{
			f(s);
			s++;
		}
	}
}
