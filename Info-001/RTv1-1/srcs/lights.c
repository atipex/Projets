/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:18:56 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:28:32 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>
#include <stdio.h>

static void			ambiant(t_color *new_color,
					t_object *object, t_light *light)
{
	new_color->r = getcolorvalue(object->material.color.r) *
	light->color.r * object->material.ambiant;
	new_color->g = getcolorvalue(object->material.color.g) *
	light->color.g * object->material.ambiant;
	new_color->b = getcolorvalue(object->material.color.b) *
	light->color.b * object->material.ambiant;
}

static t_color		diffuse(t_light *light, t_ray spot, t_object *object,
					t_coord normal)
{
	t_color	color;
	double	diff;

	diff = dot_product(spot.vector, normal);
	color.r = getcolorvalue(object->material.color.r) *
	light->color.r * object->material.diffuse * diff;
	color.g = getcolorvalue(object->material.color.g) *
	light->color.g * object->material.diffuse * diff;
	color.b = getcolorvalue(object->material.color.b) *
	light->color.b * object->material.diffuse * diff;
	return (color);
}

static t_color		specular(t_light *light, t_ray spot, t_object *object,
					t_coord normal)
{
	t_coord	reflection;
	double	spec;
	t_color	new_color;

	reflection.x = normal.x * 2 * dot_product(normal, spot.vector)
					- spot.vector.x;
	reflection.y = normal.y * 2 * dot_product(normal, spot.vector)
					- spot.vector.y;
	reflection.z = normal.z * 2 * dot_product(normal, spot.vector)
					- spot.vector.z;
	reflection = normalize(reflection);
	spec = pow(fmax(0, dot_product(reflection, spot.vector)),
			object->material.phong);
	new_color.r = getcolorvalue(object->material.color.r) *
	light->color.r * (spec * object->material.specular);
	new_color.g = getcolorvalue(object->material.color.g) *
	light->color.g * (spec * object->material.specular);
	new_color.b = getcolorvalue(object->material.color.b) *
	light->color.b * (spec * object->material.specular);
	return (new_color);
}

static int			shadows(t_list *objects, t_object *object, t_ray spot,
					t_coord inter)
{
	double	intersec;

	intersec = 0;
	while (objects)
	{
		if ((t_object *)(objects->content) != object && ((t_object *)
				(objects->content))->type != PLANE)
		{
			test_objects(objects, spot, &intersec);
			check_intersec_light(&intersec, inter, spot);
			if (intersec == 1)
				break ;
		}
		objects = objects->next;
	}
	if (intersec)
		return (1);
	return (0);
}

t_color				light(t_light *lightc, t_coord inter,
			t_object *object, t_list *objects)
{
	t_coord	normal;
	t_ray	spot;
	t_color	newcolor;

	spot.vector = normalize(vectorize(inter,
				lightc->position));
	spot.origin = lightc->position;
	ambiant(&newcolor, object, lightc);
	calculate_normal(&normal, object, inter);
	newcolor = addcolor(newcolor, diffuse(lightc, spot, object, normal));
	newcolor = addcolor(newcolor, specular(lightc, spot, object, normal));
	if (shadows(objects, object, spot, inter))
	{
		newcolor.r /= 2;
		newcolor.g /= 2;
		newcolor.b /= 2;
	}
	adjust_color(&newcolor);
	return (newcolor);
}
