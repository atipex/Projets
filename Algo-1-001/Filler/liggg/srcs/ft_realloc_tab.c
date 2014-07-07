
#include <stdlib.h>
#include <libft.h>

char		**ft_realloc_tab(char **tab, int len)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * len);
	while (tab && tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	tmp[i] = NULL;
	return (tmp);
}
