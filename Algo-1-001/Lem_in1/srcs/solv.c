#include "lem_in.h"

static int		move_f_c(t_f *f)
{
	t_path		*l;
	int			w;

	l = f->path->lab->path;
	w = 0;
	while (l->lab)
	{
		if (l->lab->used == 0 || l->lab->start == 1)
			w++;
		l = l->nxt;
	}
	return (w);
}

static t_path	*move_f_n(t_f *f, t_path *k, t_path *l)
{
	t_path		*p;
	int			nbr;

	p = f->path;
	nbr = move_f_c(f);
	while (p)
	{
		l = f->path->lab->path;
		while (l->lab)
		{
			if (l->lab == p->lab)
			{
				if (l->lab->used == 0 || l->lab->start == 1)
				{
					if (l->lab != f->path->nxt->lab || nbr == 1)
						k = l;
				}
			}
			l = l->nxt;
		}
		p = p->nxt;
	}
	return (k);
}

int				move_f(t_f *f, char s)
{
	t_path		*l;
	t_path		*k;

	k = NULL;
	l = f->path->lab->path;
	while (l->lab)
	{
		if (l->lab->start == 2)
			return (move_a(f, l, s));
		l = l->nxt;
	}
	l = f->path->lab->path;
	while (l->lab)
	{
		if (l->lab->used == 0 && already(f, l->lab))
			return (move_a(f, l, s));
		l = l->nxt;
	}
	k = move_f_n(f, k, l);
	if (k)
		return (move_a(f, k, s));
	return (0);
}

int				solv(t_f *f)
{
	t_f		*f1;

	f1 = f;
	ft_putchar('\n');
	while (issok(f))
	{
		while (f)
		{
			if (f->path->lab->start != 2)
				move_f(f, 0);
			f = f->nxt;
		}
		f = f1;
		ft_putchar('\n');
	}
	return (0);
}

int				solv_lim(t_f *f, int l)
{
	t_f		*f1;

	f1 = f;
	while (issok(f))
	{
		if (l < 0)
		{
			ft_putendl_fd("ERROR", 2);
			return (1);
		}
		while (f)
		{
			if (f->path->lab->start != 2)
				move_f(f, 1);
			f = f->nxt;
		}
		l--;
		f = f1;
	}
	return (0);
}

