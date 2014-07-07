#include "lem_in.h"
#include <stdlib.h>

t_lab	*lab_f(t_lab *lab, char **line, char start)
{
	if (error_nb(line[1]) || error_nb(line[2]))
		lab = lab_error(lab, 0);
	else if (line[0][0] == 'L')
		lab = lab_error(lab, 1);
	else if (line[0][0] == '#')
		lab = lab_error(lab, 2);
	else if (lab_find(lab, line[0]) != NULL)
		lab = lab_error(lab, 3);
	else if (lab == NULL)
		lab = lab_made(line, start);
	else
		lab_add(lab, line, start);
	return (lab);
}

t_lab	*lab_made(char **line, char start)
{
	t_lab	*lab;

	lab = (t_lab *)malloc(sizeof(t_lab));
	lab->name = ft_strdup(line[0]);
	lab->x = ft_atoi(line[1]);
	lab->y = ft_atoi(line[2]);
	lab->start = start;
	lab->used = 0;
	lab->path = path_made();
	lab->nxt = NULL;
	return (lab);
}

void	lab_add(t_lab *lab, char **line, char start)
{
	t_lab	*new;

	new = lab_made(line, start);
	while (lab->nxt)
		lab = lab->nxt;
	lab->nxt = new;
}

void	lab_del(t_lab *lab)
{
	t_lab	*tmp;

	while (lab)
	{
		tmp = lab;
		lab = lab->nxt;
		free(tmp->name);
		path_del(tmp->path);
		free(tmp);
	}
}

t_lab	*lab_find(t_lab *lab, char *name)
{
	t_lab	*find;

	find = NULL;
	while (lab)
	{
		if (ft_strcmp(name, lab->name) == 0)
		{
			find = lab;
			break ;
		}
		lab = lab->nxt;
	}
	return (find);
}

