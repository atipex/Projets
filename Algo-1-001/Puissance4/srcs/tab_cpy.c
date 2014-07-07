#include "ft_puissance4.h"
#include <stdlib.h>

void		free_cpy_tab(char ***tab1, char ***tab2)
{
	int		j;

	j = 0;
	while ((*tab1)[j] != NULL)
	{
		free((*tab1)[j]);
		(*tab1)[j] = NULL;
		j++;
	}
	free(*tab1);
	*tab1 = NULL;
	j = 0;
	while ((*tab2)[j] != NULL)
	{
		free((*tab2)[j]);
		(*tab2)[j] = NULL;
		j++;
	}
	free(*tab2);
	*tab2 = NULL;
}

char		**tab_cpy(char **tab)
{
	int		i;
	char	**ret;

	ret = NULL;
	i = glob_obj(0)->lines;
	if ((ret = (char **) malloc(sizeof(char *) * i)) == NULL)
	return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

