#include <stdlib.h>
#include "ft_puissance4.h"

void		ft_puissance4(char *s1, char *s2)
{
	t_tab		*obj;
	int			i;
	int			j;

	obj = NULL;
	if ((obj = fill_obj(s1, s2, obj)) == NULL)
		return ;
	i = ft_atoi(s1);
	j = ft_atoi(s2);
	obj->count_max = i * j;
	welcome(obj);
	obj->end = 0;
	ft_match(obj, 0);
	free_tab(obj->tab);
	free(obj);
	return ;
}

int			main(int ac, char **av)
{
	if (check_data(ac, av) == 0)
		ft_puissance4(av[1], av[2]);
	return (0);
}

