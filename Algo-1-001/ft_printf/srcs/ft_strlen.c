#include "ft.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter += 1;
	return (counter);
}
