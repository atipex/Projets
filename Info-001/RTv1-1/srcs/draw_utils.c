/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:18:32 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:37:02 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>
#include <mlx.h>

void			debug(t_color *col, t_object *object)
{
	col->r = object->material.color.r;
	col->g = object->material.color.g;
	col->b = object->material.color.b;
}

t_ray			init_ray(t_env *e, t_coord pos)
{
	t_ray	ray;

	ray.origin = e->camera.position;
	ray.vector = vectorize(ray.origin, e->view);
	ray.vector.x += pos.x;
	ray.vector.y += pos.y;
	apply_rotation(&e->camera.rotation, &ray.vector);
	ray.vector = normalize(ray.vector);
	return (ray);
}

void			init_view(t_env *e)
{
	e->view.x = e->camera.position.x - ((int)WIN_WIDTH / 2);
	e->view.y = e->camera.position.y - ((int)WIN_HEIGHT / 2);
	e->view.z = ((int)WIN_WIDTH) / (2 * tan(((int)FOV * (M_PI / 180)) / 2));
}

double			check_min(double delta, double a, double b, double c)
{
	double		t1;
	double		t2;
	double		t;

	if (a == 0)
		return ((-1) * (c / b));
	if (delta >= 0)
	{
		t1 = (((-1) * b) + sqrt(delta)) / (2 * a);
		t2 = (((-1) * b) - sqrt(delta)) / (2 * a);
		t = (t1 < t2 ? t1 : t2);
		return (t);
	}
	return (0);
}

void			mlx_put_pixel_to_image(t_env *e, int x, int y, t_color c)
{
	if (e->img.endian)
	{
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8] =
		mlx_get_color_value(e->mlx_info.mlx, c.r);
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 1] =
		mlx_get_color_value(e->mlx_info.mlx, c.g);
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 2] =
		mlx_get_color_value(e->mlx_info.mlx, c.b);
	}
	else
	{
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8] =
		mlx_get_color_value(e->mlx_info.mlx, c.b);
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 1] =
		mlx_get_color_value(e->mlx_info.mlx, c.g);
		e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 2] =
		mlx_get_color_value(e->mlx_info.mlx, c.r);
	}
}
