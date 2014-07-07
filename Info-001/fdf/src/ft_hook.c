/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:19:58 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:20:01 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		ft_expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 40, 40);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putendl(e->map);
	ft_putstr("Mouse : ");
	ft_putnbr(button);
	ft_putstr(" x:");
	ft_putnbr(x);
	ft_putstr(" y:");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	ft_putendl(e->map);
	if (keycode == 65307)
	{
		ft_putendl("Exiting ...");
		exit(keycode);
	}
	ft_putstr("Key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
