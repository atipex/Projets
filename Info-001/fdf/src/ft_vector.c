/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:20:18 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:20:21 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void		ft_if(t_data *d, t_env **env, t_color *c)
{
	int		i;

	i = 1;
	d->cumul = d->dx / 2;
	while (i <= d->dx)
	{
		d->x += d->xinc;
		d->cumul += d->dy;
		if (d->cumul >= d->dx)
		{
			d->cumul -= d->dx;
			d->y += d->yinc;
		}
		ft_pixel_put(*env, d->x, d->y, c);
		i++;
	}
}

static void		ft_else(t_data *d, t_env **env, t_color *c)
{
	int		i;

	i = 1;
	{
		d->cumul = d->dy / 2;
		while (i <= d->dy)
		{
			d->y += d->yinc;
			d->cumul += d->dx;
			if (d->cumul >= d->dy)
			{
				d->cumul -= d->dy;
				d->x += d->xinc;
			}
			ft_pixel_put(*env, d->x, d->y, c);
			i++;
		}
	}
}

void			ft_vector(t_vec *vec, t_env **env)
{
	t_data	d;
	t_color	c;
	t_env	*e;

	e = *env;
	d.x = vec->xi;
	d.y = vec->yi;
	d.dx = vec->xf - vec->xi;
	d.dy = vec->yf - vec->yi;
	d.xinc = (d.dx > 0) ? 1 : -1;
	d.yinc = (d.dy > 0) ? 1 : -1;
	d.dx = ft_abs(d.dx);
	d.dy = ft_abs(d.dy);
	c.b = 255;
	c.g = 255;
	c.r = 255;
	ft_pixel_put(e, d.x, d.y, &c);
	if (d.dx > d.dy)
		ft_if(&d, &e, &c);
	else
		ft_else(&d, &e, &c);
}
