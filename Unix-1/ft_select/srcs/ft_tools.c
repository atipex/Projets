/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:21:17 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:21:19 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ft_select.h"

int		ft_putchari(int c)
{
	write(isatty(FD_STD_OUT), &c, 1);
	return (1);
}

int		ft_putchar_output(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_clear_screen(t_data *d)
{
	int		i;

	i = -1;
	tputs(tgetstr("dm", NULL), 1, ft_putchari);
	while (++i < d->row)
		tputs(tgetstr("dl", NULL), 1, ft_putchari);
	tputs(tgetstr("ed", NULL), 1, ft_putchari);
	tputs(tgetstr("cl", NULL), 1, ft_putchari);
}

void	*ft_get_data(void)
{
	static t_data		*d = NULL;

	if (d == NULL)
		d = (t_data *)malloc(sizeof(t_data));
	return (d);
}

void	ft_get_winsize(t_data *d)
{
	struct winsize		w;

	ioctl(isatty(FD_STD_OUT), TIOCGWINSZ, &w);
	d->row = w.ws_row;
	d->col = w.ws_col;
}
