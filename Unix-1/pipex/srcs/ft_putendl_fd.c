#include <unistd.h>
#include "pipex.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	c;

	c = '\n';
	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, &c, 1);
}
