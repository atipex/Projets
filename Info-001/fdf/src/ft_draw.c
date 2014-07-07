/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:19:37 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:19:42 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_line(t_env *e)
{
	t_pts	*pts;
	t_vec	v;
	int		coef;

	pts = e->pts;
	if (e->xnbr < 200)
		coef = 25;
	else
		coef = 4;
	while (pts->next)
	{
		if (pts->y == pts->next->y)
		{
			v.xi = pts->x * coef - pts->z + 10;
			v.yi = pts->y * coef - pts->z + 10;
			v.xf = pts->next->x * coef - pts->next->z + 10;
			v.yf = pts->next->y * coef - pts->next->z + 10;
		}
		ft_vector(&v, &e);
		pts = pts->next;
	}
}

void			ft_draw_col(t_env *e)
{
	t_pts	*ptr;
	t_pts	*ptr2;
	t_vec	v;
	int		coef;

	ptr = e->pts;
	if (e->xnbr < 200)
		coef = 25;
	else
		coef = 4;
	while (ptr->next)
	{
		ptr2 = ptr->next;
		while (ptr->x != ptr2->x && ptr2->next)
			ptr2 = ptr2->next;
		v.xi = ptr->x * coef - ptr->z + 10;
		v.yi = ptr->y * coef - ptr->z + 10;
		v.xf = ptr2->x * coef - ptr2->z + 10;
		v.yf = ptr2->y * coef - ptr2->z + 10;
		ft_vector(&v, &e);
		ptr = ptr->next;
	}
}
