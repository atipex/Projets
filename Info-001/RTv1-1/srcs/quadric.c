/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:21:07 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:54:54 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <math.h>

double			get_a(t_var v, t_ray ray)
{
	return (v.a * pow(ray.vector.x, 2) + v.b * pow(ray.vector.y, 2)
	+ v.c * pow(ray.vector.z, 2) + (v.d * ray.vector.x * ray.vector.y)
	+ (v.e * ray.vector.y * ray.vector.z)
	+ (v.f * ray.vector.x * ray.vector.z));
}

double			get_b(t_var v, t_ray ray, t_coord *position)
{
	return (2 * ((v.a * (ray.origin.x - position->x) * ray.vector.x)
	+ (v.b * (ray.origin.y - position->y) * ray.vector.y)
	+ (v.c * (ray.origin.z - position->z) * ray.vector.z)
	+ (v.d * (((ray.origin.x - position->x) * ray.vector.y)
	+ ((ray.origin.y - position->y) * ray.vector.x)))
	+ (v.e * (((ray.origin.y - position->y) * ray.vector.z)
	+ ((ray.origin.z - position->z) * ray.vector.y)))
	+ (v.f * (((ray.origin.x - position->x) * ray.vector.z)
	+ ((ray.origin.z - position->z) * ray.vector.x)))
	+ (v.g * ray.vector.x) + (v.h * ray.vector.y) + (v.j * ray.vector.z)));
}

double			get_c(t_var v, t_ray ray, t_coord *position)
{
	return ((v.a * pow((ray.origin.x - position->x), 2))
	+ (v.b * pow((ray.origin.y - position->y), 2))
	+ (v.c * pow((ray.origin.z - position->z), 2))
	+ (2 * v.d * (ray.origin.x - position->x)
	* (ray.origin.y - position->y))
	+ (2 * v.e * (ray.origin.y - position->y)
	* (ray.origin.z - position->z))
	+ (2 * v.f * (ray.origin.x - position->x)
	* (ray.origin.z - position->z))
	+ (2 * v.g * (ray.origin.x - position->x))
	+ (2 * v.h * (ray.origin.y - position->y))
	+ (2 * v.j * (ray.origin.z - position->z)) + v.k);
}

t_coord			tmp1(t_ray ray, t_coord axe)
{
	t_coord		tmp1;

	tmp1.x = ray.vector.x - (dot_product(ray.vector, axe) * axe.x);
	tmp1.y = ray.vector.y - (dot_product(ray.vector, axe) * axe.y);
	tmp1.z = ray.vector.z - (dot_product(ray.vector, axe) * axe.z);
	return (tmp1);
}

t_coord			tmp2(t_coord delt_p, t_coord axe)
{
	t_coord		tmp2;

	tmp2.x = (delt_p.x) - (dot_product(delt_p, axe) * axe.x);
	tmp2.y = (delt_p.y) - (dot_product(delt_p, axe) * axe.y);
	tmp2.z = (delt_p.z) - (dot_product(delt_p, axe) * axe.z);
	return (tmp2);
}
