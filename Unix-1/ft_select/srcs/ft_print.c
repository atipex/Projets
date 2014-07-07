/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:21:04 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:21:31 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

void	ft_print(t_data *d)
{
	t_lst	*tmp;
	int		cpt;

	d->i = -1;
	cpt = 0;
	tmp = *(d->list);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		++d->i;
		if (ft_position(d, tmp) == -1)
		{
			ft_putstr_term("Redimensionner la fenetre.\n");
			return ;
		}
		if (d->cursor == tmp)
			tputs(tgetstr("us", NULL), 1, ft_putchari);
		if (tmp->select)
			tputs(tgetstr("mr", NULL), 1, ft_putchari);
		ft_putstr_term(tmp->str);
		tputs(tgetstr("me", NULL), 1, ft_putchari);
		tmp = tmp->next;
	}
}

int		ft_position(t_data *d, t_lst *tmp)
{
	int		column_width;

	d->nb_col = d->nb_elt / d->row;
	d->nb_col += (d->nb_elt % d->row == 0) ? 0 : 1;
	d->merge = ((d->col / d->nb_col) - d->len) / 2;
	if (d->merge <= 0)
		return (-1);
	d->center = (d->len - ft_strlen(tmp->str)) / 2;
	d->center = 0;
	column_width = 2 * d->merge + d->len;
	d->pos_x = d->center + column_width * (d->i / d->row) + d->merge;
	d->pos_y = d->i % d->row;
	tputs(tgoto(tgetstr("cm", NULL), d->pos_x, d->pos_y), 1, ft_putchari);
	return (0);
}

void	ft_print_checked(t_data *d)
{
	t_lst	*tmp;
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	tmp = *(d->list);
	ft_clear_screen(d);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		if (tmp->select == 1)
		{
			if (i != 0)
				ft_putchar(' ');
			ft_putstr(tmp->str);
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_error(char *msg)
{
	write(isatty(FD_STD_ERR), msg, ft_strlen(msg));
	write(isatty(FD_STD_ERR), "\n", 1);
	exit(-1);
}

void	ft_putstr_term(char *str)
{
	ft_putstr_fd(str, isatty(FD_STD_OUT));
}
