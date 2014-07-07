/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:19:50 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:19:53 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_grid(t_env *e)
{
	t_pts	*coord;
	t_color	c;
	int		x;
	int		y;

	coord = e->pts;
	c.r = 255;
	while (coord)
	{
		x = (coord->x) * 4 + 10 - coord->z;
		y = (coord->y) * 4 + 10 - coord->z;
		if (coord->z != 0)
		{
			c.b = 0;
			c.g = 0;
		}
		else
		{
			c.b = 255;
			c.g = 255;
		}
		ft_pixel_put(e, x, y, &c);
		coord = coord->next;
	}
}
