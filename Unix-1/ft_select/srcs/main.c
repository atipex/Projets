/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 00:35:46 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/04 00:35:47 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

int		ft_supprime_element(t_data *d)
{
	if (d->cursor->next == *(d->list))
	{
		d->cursor = (d->cursor)->prev;
		if (ft_del_elt(d->list, (d->cursor)->next, d) == 0)
			return (-1);
	}
	else
	{
		d->cursor = (d->cursor)->next;
		if (ft_del_elt(d->list, (d->cursor)->prev, d) == 0)
			return (-1);
	}
	return (0);
}

int		ft_wait_for_it(t_data *d)
{
	while (!is_enter(d->read_char) && !is_esc(d->read_char))
	{
		if (is_arrow(d->read_char) == DOWN)
			d->cursor = (d->cursor)->next;
		if (is_arrow(d->read_char) == UP)
			d->cursor = (d->cursor)->prev;
		if (is_space(d->read_char))
		{
			(d->cursor)->select = ((d->cursor)->select == 0) ? 1 : 0;
			d->cursor = (d->cursor)->next;
		}
		if (is_delete(d->read_char) || is_del(d->read_char))
		{
			if (ft_supprime_element(d) == -1)
				return (0);
		}
		ft_clear_screen(d);
		ft_print(d);
		ft_bzero(d->read_char, 4);
		read(0, d->read_char, 4);
	}
	if (is_enter(d->read_char))
		return (1);
	return (0);
}

int		main(int ac, char const *av[])
{
	t_data				*d;
	struct termios		*old;

	ft_getsig();
	d = ft_get_data();
	old = ft_get_init_conf();
	if (ac < 2)
		ft_error("usage: ft_select choix1 choix2 choix3 ..");
	d->list = get_lst((char **)++av, d);
	d->cursor = *(d->list);
	if (tgetent(d->bp, getenv("TERM")) < 1)
		ft_error("Bad Tgetent");
	ft_init();
	d->row = tgetnum("li");
	d->col = tgetnum("co");
	tputs(tgetstr("cl", NULL), 1, ft_putchari);
	tputs(tgetstr("dl", NULL), 1, ft_putchari);
	if (ft_wait_for_it(d) == 1)
		ft_print_checked(d);
	else
		ft_clear_screen(d);
	ft_close();
	(void)old;
	return (0);
}
