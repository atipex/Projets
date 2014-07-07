
#include <stdlib.h>
#include "corewar.h"

t_chp		*root(void)
{
	t_chp	*f;

	if ((f = malloc(sizeof(*f))) == NULL)
		ft_er("Malloc error");
	f->nxt = f;
	f->prev = f;
	f->pid = -1;
	return (f);
}

void		add(t_chp *r)
{
	t_chp	*f;

	if ((f = malloc(sizeof(*f))) == NULL)
		ft_er("Malloc error");
	f->nxt = r;
	f->prev = r->prev;
	r->prev->nxt = f;
	r->prev = f;
}

void		del(t_chp *e)
{
	if (!e->f)
	{
		free(e->com);
		free(e->parsing->cont);
		free(e->parsing);
	}
	e->prev->nxt = e->nxt;
	e->nxt->prev = e->prev;
	free(e->cmd);
	free(e);
}

