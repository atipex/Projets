#include "lem_in.h"
#include <stdlib.h>

void	add_f(t_f *f)
{
	t_f		*new;

	new = create_f();
	while (f->nxt)
		f = f->nxt;
	new->id = f->id + 1;
	f->nxt = new;
}

t_f		*create_f(void)
{
	t_f		*f;

	f = (t_f *)malloc(sizeof(t_f));
	f->id = 1;
	f->path = path_made();
	f->nxt = NULL;
	return (f);
}

t_f		*nb_f(void)
{
	t_f		*f;
	char	*line;
	int		n;

	get_next_line(0, &line);
	ft_putendl(line);
	if (error_nb(line))
		return (NULL);
	n = ft_atoi(line);
	if (n < 1)
	{
		free(line);
		ft_putendl_fd("ERROR", 2);
		return (NULL);
	}
	f = create_f();
	while (n-- > 1)
		add_f(f);
	free(line);
	return (f);
}

void	del_f(t_f *f)
{
	t_f		*tmp;

	while (f)
	{
		tmp = f;
		f = f->nxt;
		path_del(tmp->path);
		free(tmp);
	}
}

void	start_f(t_lab *lab, t_f *f)
{
	while (lab)
	{
		if (lab->start == 1)
			break ;
		lab = lab->nxt;
	}
	while (f)
	{
		f->path->lab = lab;
		f = f->nxt;
	}
}
