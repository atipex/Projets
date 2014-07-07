/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:00:51 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:00:57 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_strcmp(char *s1, char *s2)
{
	return ((*s1 == *s2 && *s1) ? (ft_strcmp(++s1, ++s2)) : (*s1 - *s2));
}

int	is_usage(int argc, char *str)
{
	if (argc == 1 || ft_strcmp(str, "--help") == 0)
	{
		ft_putstr("usage: ./wolf3d [--help] map\n\n");
		ft_putstr("\t--help  print this message\n\n");
		ft_putstr("\tArrow up    -> move up\n");
		ft_putstr("\tArrow down  -> move down\n");
		ft_putstr("\tArrow left  -> turn left\n");
		ft_putstr("\tArrow right -> turn right\n");
		return (1);
	}
	return (0);
}

int	is_good_map(t_infos_mlx *infos_mlx, int **map)
{
	int	i;
	int	j;
	int	max_x;
	int	is_zero;

	j = 0;
	is_zero = 0;
	max_x = infos_mlx->env->size_x;
	while (map[j])
	{
		i = 0;
		while (i < max_x)
		{
			if (map[j][i] == 0)
				is_zero += 1;
			i = i + 1;
		}
		j = j + 1;
	}
	if ((max_x < (int)X_START || infos_mlx->env->size_y < (int)Y_START)
			|| map[(int)Y_START][(int)X_START] == 1)
		return (FAILED);
	return ((is_zero > 0) ? (1) : (FAILED));
}
