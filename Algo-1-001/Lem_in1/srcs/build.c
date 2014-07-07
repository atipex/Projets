#include "lem_in.h"
#include <stdlib.h>

static char		build_start(char *b)
{
	char	s;

	s = 0;
	if (ft_strcmp(b, "##start") == 0)
		s = 1;
	else if (ft_strcmp(b, "##end") == 0)
		s = 2;
	free(b);
	return (s);
}

static t_lab	*build_lab_l(t_lab *lab, char **line, char s, char *b)
{
	lab = lab_f(lab, line, s);
	free(b);
	tabdel(line);
	return (lab);
}

t_lab			*build_lab(t_lab *lab)
{
	char		**line;
	char		*b;
	char		start;

	while (get_next_line(0, &b))
	{
		ft_putendl(b);
		start = 0;
		if (b[0] == '#')
		{
			if ((start = build_start(b)) == 0)
				continue ;
			get_next_line(0, &b);
			ft_putendl(b);
		}
		if (tablen(line = ft_strsplit(b, ' ')) == 3)
		{
			if ((lab = build_lab_l(lab, line, start, b)) == NULL)
				break ;
		}
		else
			return (b_path(lab, b, line));
	}
	return (lab);
}

