#include "lem_in.h"

int		issok(t_f *f)
{
	while (f)
	{
		if (f->path->lab->start != 2)
			return (1);
		f = f->nxt;
	}
	return (0);
}

int		already(t_f *f, t_lab *lab)
{
	t_path	*path;

	path = f->path;
	while (path)
	{
		if (path->lab == lab)
			return (0);
		path = path->nxt;
	}
	return (1);
}

int		move_a(t_f *f, t_path *l, char s)
{
	f->path->lab->used = 0;
	f->path = path_add(f->path, l->lab);
	if (s == 0)
	{
		ft_putchar('L');
		ft_putnbr(f->id);
		ft_putchar('-');
		ft_putstr(f->path->lab->name);
		ft_putchar(' ');
	}
	f->path->lab->used = 1;
	return (1);
}

int		solv_g(t_lab *lab)
{
	int		nbr;
	t_lab	*s;
	t_f		*f;
	int		ret;

	ret = 0;
	nbr = 0;
	s = lab;
	while (s)
	{
		nbr++;
		s = s->nxt;
	}
	nbr *= 2;
	f = create_f();
	start_f(lab, f);
	if (solv_lim(f, nbr))
		ret = 1;
	del_f(f);
	return (ret);
}

