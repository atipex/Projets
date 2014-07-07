/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:21:08 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:21:10 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"

void	ft_sig_resize(void)
{
	t_data		*d;

	d = ft_get_data();
	ft_get_winsize(d);
	ft_clear_screen(d);
	ft_print(d);
}

void	ft_sig_clear(void)
{
	t_data		*d;

	d = ft_get_data();
	ft_clear_screen(d);
}

void	ft_sig_fg(void)
{
	t_data		*d;

	d = ft_get_data();
	ft_init();
	ft_print(d);
	signal(SIGTSTP, ft_sig_action);
}

void	ft_sig_action(int s)
{
	t_data		*d;

	d = ft_get_data();
	(void)d;
	if (s == SIGWINCH)
		ft_sig_resize();
	else if (s == SIGCONT)
		ft_sig_fg();
	else
	{
		ft_sig_clear();
		if (s == SIGTSTP)
		{
			ft_close();
			signal(SIGTSTP, SIG_DFL);
			ioctl(isatty(FD_STD_OUT), TIOCSTI, "\032");
		}
		else
		{
			ft_close();
			exit (0);
		}
	}
}

void	ft_getsig(void)
{
	signal(SIGTSTP, &ft_sig_action);
	signal(SIGINT, &ft_sig_action);
	signal(SIGWINCH, &ft_sig_action);
	signal(SIGTERM, &ft_sig_action);
	signal(SIGCONT, &ft_sig_action);
	signal(SIGQUIT, &ft_sig_action);
}
