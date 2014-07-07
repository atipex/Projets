#include "lem_in.h"

t_lab	*lab_error(t_lab *lab, int n)
{
	if (n == 1)
		ft_putendl_fd("ERROR", 2);
	else if (n == 2)
		ft_putendl_fd("ERROR", 2);
	else if (n == 3)
		ft_putendl_fd("ERROR", 2);
	lab_del(lab);
	return (NULL);
}

int		error_nb(char *line)
{
	int		i;

	i = 1;
	if (line[0])
	{
		if ((!(line[0] >= '0' && line[0] <= '9')) && line[0] != '-')
		{
			ft_putendl_fd("ERROR", 2);
			return (1);
		}
	}
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
		{
			ft_putendl_fd("ERROR", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int		error_start(t_lab *lab)
{
	while (lab)
	{
		if (lab->start == 1)
			break ;
		lab = lab->nxt;
	}
	if (!lab)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	lab = lab->nxt;
	while (lab)
	{
		if (lab->start == 1)
		{
			ft_putendl_fd("ERROR", 2);
			return (1);
		}
		lab = lab->nxt;
	}
	return (0);
}

int		error_end(t_lab *lab)
{
	while (lab)
	{
		if (lab->start == 1)
			break ;
		lab = lab->nxt;
	}
	if (!lab)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	lab = lab->nxt;
	while (lab)
	{
		if (lab->start == 1)
		{
			ft_putendl_fd("ERROR", 2);
			return (1);
		}
		lab = lab->nxt;
	}
	return (0);
}

