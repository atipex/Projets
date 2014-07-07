/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:19:24 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:01:41 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>

static void	normal_plane(t_object *object, t_coord *normal)
{
	normal->x = 0;
	normal->y = -1;
	normal->z = 0;
	apply_rotation(&(((t_plane *)(object->object))->rotation), normal);
	*normal = normalize(*normal);
}

static void	normal_cylinder(t_object *object, t_coord *normal, t_coord inter)
{
	t_coord	axe;
	t_coord	proj;
	double	k;

	axe.x = 0;
	axe.y = 1;
	axe.z = 0;
	apply_rotation(&(((t_cylinder *)(object->object))->rotation), &axe);
	k = ((axe.x * (inter.x - ((t_cylinder *)(object->object))->position.x))
		+ (axe.y * (inter.y - ((t_cylinder *)(object->object))->position.y))
		+ (axe.z * (inter.z - ((t_cylinder *)(object->object))->position.z)))
		/ (pow(axe.x, 2) + pow(axe.y, 2) + pow(axe.z, 2));
	proj.x = k * axe.x + ((t_cylinder *)(object->object))->position.x;
	proj.y = k * axe.y + ((t_cylinder *)(object->object))->position.y;
	proj.z = k * axe.z + ((t_cylinder *)(object->object))->position.z;
	*normal = normalize(vectorize(proj, inter));
}

static void	normal_cone(t_object *object, t_coord *normal, t_coord inter)
{
	t_var	v;

	v.a = 1;
	v.b = -1;
	v.c = 1;
	v.d = 0;
	v.e = 0;
	v.f = 0;
	v.g = 0;
	v.h = 0;
	v.i = 0;
	v.j = 0;
	normal->x = (2 * v.a * (inter.x - ((t_cone *)(object->object))->position.x))
		+ (v.d * (inter.y - ((t_cone *)(object->object))->position.y))
		+ (v.e * (inter.z - ((t_cone *)(object->object))->position.z)) + v.g;
	normal->y = (2 * v.b * (inter.y - ((t_cone *)(object->object))->position.y))
		+ (v.d * (inter.x - ((t_cone *)(object->object))->position.x))
		+ (v.f * (inter.z - ((t_cone *)(object->object))->position.z)) + v.h;
	normal->z = (2 * v.c * (inter.z - ((t_cone *)(object->object))->position.z))
		+ (v.e * (inter.x - ((t_cone *)(object->object))->position.x))
		+ (v.f * (inter.y - ((t_cone *)(object->object))->position.y)) + v.j;
	*normal = normalize(*normal);
}

void		calculate_normal(t_coord *normal, t_object *object, t_coord inter)
{
	if (object->type == SPHERE)
		*normal = normalize(vectorize(((t_sphere *)(object->object))->position,
					inter));
	else if (object->type == PLANE)
		normal_plane(object, normal);
	else if (object->type == CYLINDER)
		normal_cylinder(object, normal, inter);
	else if (object->type == CONE)
		normal_cone(object, normal, inter);
}
