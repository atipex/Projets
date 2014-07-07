/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:02:11 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:02:15 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	head_up(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->head <= 200)
	{
		infos_mlx->env->head = infos_mlx->env->head + 5;
		disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
		manage_expose(infos_mlx);
	}
}

void	head_down(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->head >= -200)
	{
		infos_mlx->env->head = infos_mlx->env->head - 5;
		disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
		manage_expose(infos_mlx);
	}
}

void	head_restore(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->head != 0)
	{
		if ((infos_mlx->env->head > 0 && infos_mlx->env->head < 25)
				|| (infos_mlx->env->head < 0 && infos_mlx->env->head > -25))
			infos_mlx->env->head = 0;
		else if (infos_mlx->env->head > 0)
			infos_mlx->env->head = infos_mlx->env->head - 25;
		else
			infos_mlx->env->head = infos_mlx->env->head + 25;
		infos_mlx->env->head = infos_mlx->env->head - 1;
		disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
		manage_expose(infos_mlx);
	}
}

void	more_rot(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->rot_speed + 5 < 100)
	{
		infos_mlx->env->rot_speed = infos_mlx->env->rot_speed + 5;
		manage_expose(infos_mlx);
	}
}

void	less_rot(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->rot_speed - 5 > 0)
	{
		infos_mlx->env->rot_speed = infos_mlx->env->rot_speed - 5;
		manage_expose(infos_mlx);
	}
}
