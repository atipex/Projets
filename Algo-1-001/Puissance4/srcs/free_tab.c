
#include <stdlib.h>
#include "ft_puissance4.h"

void		free_tab(char **tab1)
{
	int		j;

	j = 0;
	while (tab1[j] != NULL)
	{
		free(tab1[j]);
		j++;
	}
	free(tab1);
}


