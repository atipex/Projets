#include <unistd.h>

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

