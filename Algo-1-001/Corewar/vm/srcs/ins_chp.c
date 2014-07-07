#include "corewar.h"

static int		sum_mem_c(t_chp *c)
{
	t_chp		*tmp;
	int			sum;

	tmp = c->nxt->nxt;
	sum = 0;
	while (tmp != c)
	{
		sum += tmp->parsing->size;
		tmp = tmp->nxt;
	}
	return (sum);
}

static int		count_c(t_chp *c)
{
	t_chp	*tmp;
	int		count;

	tmp = c->nxt;
	count = 0;
	while (tmp != c)
	{
		count++;
		tmp = tmp->nxt;
	}
	return (count);
}

static void		put_mem(t_chp *c)
{
	int		i;

	i = 0;
	while (i < c->parsing->size && i < MEM_SIZE)
	{
		c->PC[i] = c->parsing->cont[i];
		i++;
	}
}

static void		p_o(t_chp *c, t_charu *a)
{
	t_chp		*tmp;
	int			pos;
	int			m_l;
	int			marg;
	int			sum_mem;

	pos = 0;
	tmp = c->nxt;
	m_l = MEM_SIZE - tmp->parsing->size;
	if ((sum_mem = sum_mem_c(c)) > m_l)
		ft_er("No enought memory space");
	marg = ((m_l - sum_mem) / count_c(c));
	tmp = tmp->nxt;
	while (tmp != c)
	{
		pos += (marg + tmp->prev->parsing->size);
		tmp->PC = &(a[pos]);
		put_mem(tmp);
		tmp = tmp->nxt;
	}
}

void			ins_chp(t_chp *c, t_charu *a)
{
	t_chp	*tmp;

	tmp = c->nxt;
	tmp->PC = &(a[0]);
	put_mem(tmp);
	if (tmp->nxt != c)
		p_o(c, a);
}

