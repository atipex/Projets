#include "lem_in.h"
#include <stdlib.h>

static int		b_isok(t_lab *lab1, t_lab *lab2)
{
	t_path		*cmp;

	cmp = lab1->path;
	while (cmp->lab)
	{
		if (cmp->lab == lab2)
		{
			ft_putstr_fd("ERROR", 2);
			return (1);
		}
		cmp = cmp->nxt;
	}
	return (0);
}

static int		b_link(t_lab *lab, char *n1, char *n2)
{
	t_lab		*lab1;
	t_lab		*lab2;

	lab1 = lab_find(lab, n1);
	lab2 = lab_find(lab, n2);
	if (!lab1)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	if (!lab2)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	if (b_isok(lab1, lab2))
		return (1);
	lab1->path = path_add(lab1->path, lab2);
	lab2->path = path_add(lab2->path, lab1);
	return (0);
}

static t_lab	*b_analy(t_lab *lab, char *b, char **line)
{
	line = ft_strsplit(b, '-');
	free(b);
	if (tablen(line) == 2)
	{
		if (!(b_link(lab, line[0], line[1])))
		{
			tabdel(line);
			return (NULL);
		}
	}
	tabdel(line);
	return (lab);
}

t_lab			*b_path(t_lab *lab, char *b, char **line)
{
	tabdel(line);
	if (b_analy(lab, b, line) != NULL)
		return (lab);
	while (get_next_line(0, &b))
	{
		ft_putendl(b);
		if (b[0] == '#')
		{
			free(b);
			continue ;
		}
		if (b_analy(lab, b, line) != NULL)
		{
			return (lab);
		}
	}
	return (lab);
}

