
#include <stdlib.h>
#include "ft_puissance4.h"

t_tab		*glob_obj(int i)
{
	static t_tab		*obj = NULL;

	if (i == 1)
	{
		if ((obj = (t_tab *) malloc(sizeof(t_tab))) == NULL)
			return (NULL);
	}
	return (obj);
}

char		*ft_strnew_tab(size_t size)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (size > 0)
	{
		s[i] = ' ';
		i++;
		size--;
	}
	s[i] = '\0';
	return (s);
}

char		**tab_create(int line, int cols)
{
	char	**ret;
	int		i;

	ret = NULL;
	if ((ret = (char **) malloc(sizeof(char *) * line)) == NULL)
		return (NULL);
	i = 0;
	while (i < line)
	{
		if ((ret[i] = ft_strnew_tab(cols)) == NULL)
			return (NULL);
		i++;
	}
	ret[line] = NULL;
	return (ret);
}

t_tab		*fill_obj(char *s1, char *s2, t_tab *obj)
{
	char		**ret;

	ret = NULL;
	if ((obj = glob_obj(1)) == NULL)
	return (NULL);
		obj->lines = ft_atoi(s1);
		obj->cols = ft_atoi(s2);
	if ((ret = tab_create(obj->lines, obj->cols)) == NULL)
		return (NULL);
	obj->tab = ret;
	return (obj);
}

