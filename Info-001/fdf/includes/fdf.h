/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 12:20:53 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/27 04:07:00 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct		s_pts
{
	int				x;
	int				y;
	int				z;
	struct s_pts	*next;
}					t_pts;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*map;
	int				xnbr;
	int				ynbr;
	t_pts			*pts;
}					t_env;

typedef struct		s_color
{
	int				b;
	int				g;
	int				r;
}					t_color;

typedef struct		s_vec
{
	int				xi;
	int				yi;
	int				xf;
	int				yf;
}					t_vec;

typedef struct		s_data
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_data;

t_pts				*ft_save_data(int fd, int *xnbr, int *ynbr);
int					ft_key_hook(int keycode, t_env *e);
int					ft_mouse_hook(int button, int x, int y, t_env *e);
int					ft_expose_hook(t_env *e);
void				ft_draw_line(t_env *e);
void				ft_draw_col(t_env *e);
void				ft_grid(t_env *e);
void				ft_pixel_put(t_env *e, int x, int y, t_color *c);
void				ft_vector(t_vec *vec, t_env **env);
#endif
