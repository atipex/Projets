/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:19:13 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:19:15 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <mlx.h>
#include <stdlib.h>

static void	init_img(t_env *e)
{
	int		bpp;
	int		sizeline;
	int		endian;

	e->img.data = mlx_get_data_addr(e->img.ptr, &bpp, &sizeline, &endian);
	e->img.sizeline = sizeline;
	e->img.bpp = bpp;
	e->img.endian = endian;
}

static int	expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

static int	key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->debug = 0;
	e->objects = NULL;
	e->lights = NULL;
	init_parser(e, ac, av);
	e->mlx_info.mlx = mlx_init();
	e->mlx_info.win = mlx_new_window(e->mlx_info.mlx,
					WIN_WIDTH, WIN_HEIGHT, "RTv1");
	e->img.ptr = mlx_new_image(e->mlx_info.mlx, WIN_WIDTH, WIN_HEIGHT);
	init_img(e);
	mlx_expose_hook(e->mlx_info.win, expose_hook, e);
	mlx_key_hook(e->mlx_info.win, key_hook, e);
	mlx_loop(e->mlx_info.mlx);
	return (0);
}
