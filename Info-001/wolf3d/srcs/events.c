/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:01:11 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:01:13 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "wolf.h"

void			put_rot(t_infos_mlx *infos_mlx)
{
	char		speed[5];

	speed[4] = 0;
	speed[0] = '0' + (infos_mlx->env->rot_speed / 10);
	speed[1] = '.';
	speed[2] = '0' + (infos_mlx->env->rot_speed % 10);
	speed[3] = 'x';
	mlx_string_put(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
			(WIDTH - 170), (HEIGHT - 30),
			COLOR_STRINGS, "Rotation speed :");
	mlx_string_put(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
			(WIDTH - 45), (HEIGHT - 30), COLOR_STRINGS, speed);
}

void			put_walk(t_infos_mlx *infos_mlx)
{
	char		walk[2];

	walk[1] = 0;
	walk[0] = '0' + (infos_mlx->env->walk_speed);
	mlx_string_put(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
			(WIDTH - 170), (HEIGHT - 15),
			COLOR_STRINGS, "Walking speed     :");
	mlx_string_put(infos_mlx->mlx_ptr, infos_mlx->win_ptr,
			(WIDTH - 45), (HEIGHT - 15), COLOR_STRINGS, walk);
}

int				manage_expose(void *param)
{
	t_infos_mlx	*infos_mlx;

	infos_mlx = param;
	mlx_put_image_to_window(infos_mlx->mlx_ptr,
			infos_mlx->win_ptr,
			infos_mlx->img, 0, 0);
	put_rot(infos_mlx);
	put_walk(infos_mlx);
	return (0);
}

static int		do_func(int keycode, t_functions *list_func,
				t_infos_mlx *infos_mlx)
{
	void		(*func_ptr)(t_infos_mlx *infos_mlx);

	while (list_func && keycode != list_func->keycode)
		list_func = list_func->next;
	if (list_func && list_func->keycode == keycode)
	{
		func_ptr = (list_func->func_ptr);
		func_ptr(infos_mlx);
	}
	return (0);
}

int				manage_key(int keycode, t_infos_mlx *infos_mlx)
{
	do_func(keycode, infos_mlx->env->list_func, infos_mlx);
	return (0);
}
