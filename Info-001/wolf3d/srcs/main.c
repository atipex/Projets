/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 13:02:04 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 13:02:05 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "wolf.h"

static int			init_infos_mlx(t_infos_mlx **infos_mlx)
{
	if (((*infos_mlx)->mlx_ptr = mlx_init()) == NULL)
		return (ft_puterror(MLX_ERROR));
	if (((*infos_mlx)->win_ptr = mlx_new_window((*infos_mlx)->mlx_ptr,
	WIDTH, HEIGHT, WINDOW_TITLE)) == NULL)
		return (ft_puterror(MLX_ERROR));
	if (((*infos_mlx)->img = mlx_new_image((*infos_mlx)->mlx_ptr,
	WIDTH, HEIGHT)) == NULL)
		return (ft_puterror(MLX_ERROR));
	(*infos_mlx)->data = mlx_get_data_addr((*infos_mlx)->img,
	&((*infos_mlx)->bpp), &((*infos_mlx)->sizeline),
	&((*infos_mlx)->endian));
	return (0);
}

static void			init_env(t_env *env)
{
	env->angle = ANGLE_START;
	env->x = X_START;
	env->y = Y_START;
	env->head = HEAD_START;
	env->rot_speed = ROT_START;
	env->walk_speed = WALK_START;
}

void				disp_img(t_infos_mlx *infos_mlx, int **map, t_env *env)
{
	unsigned int	color;
	int				x;
	float			dist_wall;
	float			each_x;

	x = 0;
	each_x = 0.5;
	while (x < WIDTH)
	{
		dist_wall = find_wall(env, map, each_x, &color);
		if (dist_wall < 0.5)
			dist_wall = 0.5;
		print_line(get_coord(x, 0, x, (HEIGHT / 2) - (HEIGHT / (2 * dist_wall))
		+ env->head), infos_mlx, SKY_COLOR);
		print_line(get_coord(x, (HEIGHT / 2) - (HEIGHT / (2 * dist_wall))
		+ env->head, x, (HEIGHT / 2)
		+ (HEIGHT / (2 * dist_wall)) + env->head),
		infos_mlx, color);
		print_line(get_coord(x, (HEIGHT / 2) + (HEIGHT / (2 * dist_wall)
		+ env->head), x, HEIGHT),
		infos_mlx, FLOOR_COLOR);
		x = x + 1;
		each_x = each_x - (1.0 / (float)WIDTH);
	}
}

int					main(int argc, char **argv)
{
	t_infos_mlx		*infos_mlx;

	infos_mlx = NULL;
	if (is_usage(argc, argv[1]) == 1)
		return (0);
	if (((infos_mlx = (t_infos_mlx*)malloc(sizeof(t_infos_mlx))) == NULL)
	|| ((infos_mlx->env = (t_env*)malloc(sizeof(t_env))) == NULL)
	|| (infos_mlx->env->list_func = init_func()) == NULL)
		return (ft_puterror(ALLOC_ERROR));
	if ((infos_mlx->env->map = get_map(argv[1], infos_mlx->env)) == NULL)
		return (FAILED);
	if (is_good_map(infos_mlx, infos_mlx->env->map) == FAILED)
		return (ft_puterror(MAP_ERROR));
	if ((init_infos_mlx(&infos_mlx)) == FAILED)
		return (FAILED);
	init_env(infos_mlx->env);
	disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
	mlx_hook(infos_mlx->win_ptr, KEYPRESS, KEYPRESSMASK, manage_key, infos_mlx);
	mlx_expose_hook(infos_mlx->win_ptr, manage_expose, infos_mlx);
	mlx_loop(infos_mlx->mlx_ptr);
	return (0);
}
