
#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 7);
	else
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
}

int		ft_int_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 7);
	else
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
	return (1);
}
