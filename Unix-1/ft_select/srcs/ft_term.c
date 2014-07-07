/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:21:13 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:21:14 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "ft_select.h"

struct termios	*ft_get_init_conf(void)
{
	static struct termios	*old = NULL;

	if (old == NULL)
	{
		old = (struct termios *)malloc(sizeof(struct termios));
		if (tcgetattr(0, old) != 0)
			ft_error("bad tcgetattr");
	}
	return (old);
}

void			ft_init(void)
{
	struct termios		term;

	if (tcgetattr(0, &term) != 0)
		ft_error("bad tcgetattr");
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~ICANON;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		ft_error("bad tcsetattr");
	tputs(tgetstr("ti", NULL), 1, ft_putchari);
	tputs(tgetstr("vi", NULL), 1, ft_putchari);
}

void			ft_close(void)
{
	struct termios			*old;

	old = ft_get_init_conf();
	tcsetattr(0, TCSANOW, old);
	tputs(tgetstr("cl", NULL), 1, ft_putchari);
	tputs(tgetstr("ve", NULL), 1, ft_putchari);
	tputs(tgetstr("te", NULL), 1, ft_putchari);
}
