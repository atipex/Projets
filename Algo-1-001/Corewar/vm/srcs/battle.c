#include "corewar.h"
#include <stdlib.h>

void		del_m_f(t_chp *r, t_chp *tmp)
{
	t_chp	*t;

	t = r->nxt;
	while (t != r)
	{
		t = t->nxt;
		if (t->prev != tmp && t->prev->f == t->pid)
			del_m_f(r, t->prev);
	}
	del(tmp);
}

void		clean(t_chp *chp, t_cycle *c, t_charu *a)
{
	t_chp	*tmp;

	free(a);
	free(c);
	tmp = chp->nxt;
	while (tmp != chp)
	{
		tmp = tmp->nxt;
		del(tmp->prev);
	}
	free(chp);
	exit(0);
}

void		is_win(t_charu *a, t_chp *chp, t_cycle *c)
{
	if (g_winner_name)
	{
		ft_putstr("Le joueur ");
		ft_putstr(g_winner_name);
		ft_putstr(" (");
		ft_putnbr(g_winner_id);
		ft_putendl(") a gagne");
	}
	else
		ft_putendl("Egalitee");
	clean(chp, c, a);
}

void		battle_start(int d, t_charu *a, t_chp *chp, t_cycle *c)
{
	t_chp	*tmp;

	while (c->cycle_to_die > 0 && check_r(chp, c))
	{
		tmp = chp->nxt;
		while (tmp != chp)
		{
			check_cy(tmp, a, c);
			tmp->cycle_to_die++;
			tmp = tmp->nxt;
			if (c->nbr_live >= NBR_LIVE)
			{
				c->cycle_to_die -= CYCLE_DELTA;
				c->nbr_live = 0;
			}
		}
		if (c->current_cycle == d)
			d_mem(chp, c, a);
		c->current_cycle++;
	}
	is_win(a, chp, c);
}

