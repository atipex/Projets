/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:18:18 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:49:06 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <rtv1.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libft.h>

void			apply_rotation(t_coord *rotation, t_coord *normal)
{
	t_var	v;

	v.a = cos(rotation->x * (M_PI / 180));
	v.b = sin(rotation->x * (M_PI / 180));
	v.c = cos(rotation->y * (M_PI / 180));
	v.d = sin(rotation->y * (M_PI / 180));
	v.e = cos(rotation->z * (M_PI / 180));
	v.f = sin(rotation->z * (M_PI / 180));
	normal->x += (normal->x * (v.c * v.e)) + (normal->y * (-1) * (v.c * v.f))
		+ (normal->z * (-1) * v.d);
	normal->y += (normal->x * (((-1) * (v.b * v.d * v.e)) + (v.a * v.f)))
		+ (normal->y * (((-1) * (v.b * v.d * v.f)) + (v.a * v.e)))
		+ (normal->z * (-1) * (v.b * v.c));
	normal->z += (normal->x * (((v.a * v.d * v.e) + (v.b * v.f))))
		+ (normal->y * (((-1) * (v.a * v.d * v.f)) + (v.b * v.e)))
		+ (normal->z * (v.a * v.c));
}

void			test_objects(t_list *objects, t_ray ray, double *t)
{
	if (((t_object *)(objects->content))->type == SPHERE)
		*t = intersection_sphere(((t_sphere *)(((t_object *)
							(objects->content))->object)), ray);
	if (((t_object *)(objects->content))->type == PLANE)
		*t = intersection_plane(((t_plane *)(((t_object *)
							(objects->content))->object)), ray);
	if (((t_object *)(objects->content))->type == CYLINDER)
		*t = intersection_cylinder(((t_cylinder *)(((t_object *)
							(objects->content))->object)), ray);
	if (((t_object *)(objects->content))->type == CONE)
		*t = intersection_cone(((t_cone *)(((t_object *)
							(objects->content))->object)), ray);
}

t_object		*intersection(t_list *objects, t_ray ray, double *t)
{
	double		dmin;
	t_object	*objectmin;
	double		tmin;

	dmin = -1;
	objectmin = (t_object *)malloc(sizeof(t_object));
	objectmin->type = NONE;
	tmin = 0;
	while (objects)
	{
		test_objects(objects, ray, t);
		if (*t)
		{
			if (dmin == -1
			|| norm_vect(vectorize(ray.origin, pt_inter(ray, *t))) < dmin)
			{
				tmin = *t;
				dmin = norm_vect(vectorize(ray.origin, pt_inter(ray, *t)));
				objectmin = (t_object *)(objects->content);
			}
		}
		objects = objects->next;
	}
	*t = tmin;
	return (objectmin);
}

t_color			calcolor(t_env *e, t_list *objects, t_ray ray, t_list *lights)
{
	t_list		*tmp;
	t_color		col;
	t_object	*object;
	int			i;
	double		t;

	(void)e;
	ft_init_col(&col);
	i = -1;
	tmp = lights;
	object = intersection(objects, ray, &t);
	if (object)
	{
		while (i++, tmp)
		{
			col = addcolor(col, light((t_light *)(tmp->content)
			, pt_inter(ray, t), object, objects));
			tmp = tmp->next;
		}
		col.r = col.r / i;
		col.g = col.g / i;
		col.b = col.b / i;
	}
	return (col);
}

void			draw(t_env *e)
{
	t_coord		pos;
	t_ray		ray;

	pos.x = 0.5;
	while (pos.x < WIN_WIDTH)
	{
		pos.y = 0.5;
		while (pos.y < WIN_HEIGHT)
		{
			init_view(e);
			ray = init_ray(e, pos);
			mlx_put_pixel_to_image(e, pos.x, pos.y,
			calcolor(e, e->objects, ray, e->lights));
			++pos.y;
		}
		++pos.x;
	}
	mlx_put_image_to_window(e->mlx_info.mlx, e->mlx_info.win, e->img.ptr, 0, 0);
	ft_putendl("findurendu");
}
