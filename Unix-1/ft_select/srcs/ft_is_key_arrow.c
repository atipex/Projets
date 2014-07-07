/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_key_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:20:55 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/02 18:20:56 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		is_arrow(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91)
	{
		if (buf[2] == 65)
			return (UP);
		else if (buf[2] == 66)
			return (DOWN);
		else if (buf[2] == 68)
			return (LEFT);
		else if (buf[2] == 67)
			return (RIGHT);
	}
	return (NOT_ARROW);
}
