/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:19:09 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:02:37 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	adjust_color(t_color *new_color)
{
	if (new_color->r > 255)
		new_color->r = 255;
	if (new_color->g > 255)
		new_color->g = 255;
	if (new_color->b > 255)
		new_color->b = 255;
	if (new_color->r < 0)
		new_color->r = 0;
	if (new_color->g < 0)
		new_color->g = 0;
	if (new_color->b < 0)
		new_color->b = 0;
}

void	check_intersec_light(double *intersec, t_coord inter, t_ray spot)
{
	t_coord	inter_light;

	if (*intersec != 0)
	{
		inter_light = pt_inter(spot, *intersec);
		if (norm_vect(vectorize(inter_light, spot.origin))
				< norm_vect(vectorize(inter, spot.origin)))
			*intersec = 1;
		else
			*intersec = 0;
	}
}
