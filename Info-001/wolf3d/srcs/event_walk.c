/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:01:05 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:01:08 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	speed_up(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->walk_speed + 1 < 6)
	{
		infos_mlx->env->walk_speed += 1;
		manage_expose(infos_mlx);
	}
}

void	speed_down(t_infos_mlx *infos_mlx)
{
	if (infos_mlx->env->walk_speed - 1 > 0)
	{
		infos_mlx->env->walk_speed -= 1;
		manage_expose(infos_mlx);
	}
}
