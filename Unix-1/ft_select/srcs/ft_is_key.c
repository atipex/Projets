/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:20:46 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:20:52 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		is_space(char *buf)
{
	return (buf[0] == 32);
}

int		is_enter(char *buf)
{
	return (buf[0] == 10 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0);
}

int		is_del(char *buf)
{
	return (buf[0] == 127);
}

int		is_delete(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126);
}

int		is_esc(char *buf)
{
	return (buf[0] == 27 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0);
}
