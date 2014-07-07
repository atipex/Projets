/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:20:07 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:20:09 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_env *e, int x, int y, t_color *c)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	if (endian == 0)
	{
		data[(y * sizeline) + x * (bpp / 8)] = c->b;
		data[(y * sizeline) + x * (bpp / 8) + 1] = c->g;
		data[(y * sizeline) + x * (bpp / 8) + 2] = c->r;
	}
	else
	{
		data[(y * sizeline) + x * (bpp / 8)] = c->r;
		data[(y * sizeline) + x * (bpp / 8) + 1] = c->g;
		data[(y * sizeline) + x * (bpp / 8) + 2] = c->b;
	}
}
