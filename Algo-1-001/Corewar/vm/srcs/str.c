
#include "corewar.h"
#include <stdlib.h>

void	ft_er(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}

char	*ft_ustrndup(unsigned char *str, int n)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen((char*)str) + 1);
	if (s == NULL)
		exit(-1);
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

