/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:20:28 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:20:29 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void		ft_init_fdf(t_pts **root, int xnbr, int ynbr)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1440, 900, "fdf");
	e.img = mlx_new_image(e.mlx, 1440, 900);
	e.pts = *root;
	e.xnbr = xnbr;
	e.ynbr = ynbr;
	e.map = ft_strdup("fdf");
	ft_draw_line(&e);
	ft_draw_col(&e);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop(e.mlx);
}

int				main(int ac, char **av)
{
	int			fd;
	int			xnbr;
	int			ynbr;
	t_pts		*pts;

	if (ac != 2)
	{
		ft_putendl_fd("fdf : Error", 2);
		ft_putendl_fd("usage 'map'.fdf", 2);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl_fd("fdf : Error cannot open file properly", 2);
		exit(0);
	}
	pts = ft_save_data(fd, &xnbr, &ynbr);
	ft_init_fdf(&pts, xnbr, ynbr);
	return (0);
}
