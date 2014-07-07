
#include <string.h>

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			*s = 0;
			s++;
		}
	}
}
