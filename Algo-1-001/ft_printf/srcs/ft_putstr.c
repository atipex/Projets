#include <unistd.h>
#include "ft.h"

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[counter])
	{
		ft_putchar(s[counter]);
		counter += 1;
	}
	return (counter);
}
