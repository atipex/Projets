
#include <stdlib.h>
#include <string.h>

void	ft_strdel(char **as)
{
	if (as != '\0')
	{
		free (*as);
		*as = NULL;
	}
}
