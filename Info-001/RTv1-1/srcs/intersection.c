/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:18:49 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:11:25 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>

double			intersection_cone(t_cone *cone, t_ray ray)
{
	double	delta;
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
	v.k = 0;
	delta = pow(get_b(v, ray, &cone->position), 2)
	- (4 * get_a(v, ray) * get_c(v, ray, &cone->position));
	return (check_min(delta, get_a(v, ray),
	get_b(v, ray, &cone->position), get_c(v, ray, &cone->position)));
}

double			intersection_plane(t_plane *plane, t_ray ray)
{
	t_coord	normal;
	t_coord	plan;
	double	t;

	normal.x = 0;
	normal.y = 1;
	normal.z = 0;
	apply_rotation(&(plane->rotation), &normal);
	normal = normalize(normal);
	plan = vectorize(ray.origin, plane->position);
	if (dot_product(ray.vector, normal) == 0)
		return (0);
	t = -(dot_product(plan, normal) / dot_product(ray.vector, normal));
	if (t >= 0)
		return (t);
	return (0);
}

double			intersection_cylinder(t_cylinder *cylinder, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_coord		axe;
	t_coord		delt_p;

	axe.x = 0;
	axe.y = 1;
	axe.z = 0;
	apply_rotation(&cylinder->rotation, &axe);
	axe = normalize(axe);
	delt_p = vectorize(cylinder->position, ray.origin);
	a = dot_product(tmp1(ray, axe), tmp1(ray, axe));
	b = 2 * (dot_product(tmp1(ray, axe), tmp2(delt_p, axe)));
	c = dot_product(tmp2(delt_p, axe), tmp2(delt_p, axe))
		- pow(cylinder->radius, 2);
	return (check_min(pow(b, 2) - (4 * a * c), a, b, c));
}

double			intersection_sphere(t_sphere *sphere, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	double		delta;

	a = pow(ray.vector.x, 2) + pow(ray.vector.y, 2) + pow(ray.vector.z, 2);
	b = 2 * ((ray.vector.x * (ray.origin.x - sphere->position.x)) +
			((ray.origin.y - sphere->position.y) * ray.vector.y)
			+ ((ray.origin.z - sphere->position.z) * ray.vector.z));
	c = pow(ray.origin.x - sphere->position.x, 2) + pow(ray.origin.y
		- sphere->position.y, 2) + pow(ray.origin.z - sphere->position.z, 2)
		- pow(sphere->radius, 2);
	delta = pow(b, 2) - (4 * a * c);
	return (check_min(delta, a, b, c));
}
