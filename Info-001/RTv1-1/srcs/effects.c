/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 17:12:04 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:51:28 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>
#include <stdio.h>

t_color				addcolor(t_color c1, t_color c2)
{
	t_color		tmp;

	tmp.r = c1.r + c2.r;
	tmp.g = c1.g + c2.g;
	tmp.b = c1.b + c2.b;
	return (tmp);
}

double				getcolorvalue(int color)
{
	double	res;

	res = (double)color / 255;
	res = (res < 0.1 ? 0.1 : res);
	return (res);
}

void				ft_init_col(t_color *col)
{
	col->r = 0;
	col->g = 0;
	col->b = 0;
}
