/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:23:36 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 17:49:38 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define FOV 45

# include <libft.h>

enum
{
	SPHERE,
	PLANE,
	CUBE,
	CYLINDER,
	CONE,
	NONE,
	SPOT,
	POINT
};

typedef struct	s_var
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
	double		f;
	double		g;
	double		h;
	double		i;
	double		j;
	double		k;
}				t_var;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			sizeline;
	int			bpp;
	int			endian;
	t_color		c;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_sphere
{
	t_coord		position;
	t_coord		rotation;
	double		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_coord		position;
	t_coord		rotation;
}				t_plane;

typedef struct	s_cube
{
	t_coord		position;
	double		height;
	double		depth;
	double		width;
	t_coord		rotation;
}				t_cube;

typedef struct	s_cylinder
{
	t_coord		position;
	t_coord		rotation;
	double		height;
	double		radius;
}				t_cylinder;

typedef struct	s_cone
{
	t_coord		position;
	double		height;
	double		radius;
	t_coord		rotation;
}				t_cone;

typedef struct	s_light
{
	int			type;
	t_coord		position;
	t_coord		rotation;
	t_color		color;
	double		intensity;
}				t_light;

typedef struct	s_camera
{
	t_coord		position;
	t_coord		rotation;
}				t_camera;

typedef struct	s_ray
{
	t_coord		vector;
	t_coord		origin;
}				t_ray;

typedef struct	s_material
{
	double		ambiant;
	double		diffuse;
	double		specular;
	double		phong;
	t_color		color;
}				t_material;

typedef struct	s_object
{
	int			type;
	void		*object;
	t_material	material;
}				t_object;

typedef struct	s_env
{
	int			debug;
	t_mlx		mlx_info;
	t_camera	camera;
	t_list		*objects;
	t_list		*lights;
	t_coord		view;
	t_img		img;
}				t_env;

void			add_or_create_list(t_list **addto, void *toadd, int size);
int				parse_objects_line(t_env *e, char *line, int *ii, int fd);
void			file_error(int type, char *info1, char *info2);
int				parse_position(char *str, t_coord *pos);
int				parse_rotation(char *str, t_coord *rot);
int				parse_color(char *str, t_color *c);
int				not_double(char *str);
int				parse_size(char *str, double *size);
int				parse_item(int fd, t_env *e, char *line,
				int (*f)(t_env *, char *, int *, int fd));
int				parse_lights_line(t_env *e, char *line, int *i, int fd);
void			print_parser(t_env *e);
int				parse_material_line(t_env *e, char *line, int *i, int fd);
void			init_parser(t_env *e, int ac, char **av);
t_coord			vectorize(t_coord a, t_coord b);
double			norm_vect(t_coord vector);
double			dot_product(t_coord a, t_coord b);
t_coord			normalize(t_coord vect);
t_coord			pt_inter(t_ray ray, double t);
t_color			light(t_light *lightc,
				t_coord inter, t_object *object, t_list *objects);
void			calculate_normal(t_coord *normal,
				t_object *object, t_coord inter);
double			intersection_sphere(t_sphere *sphere, t_ray ray);
double			intersection_cylinder(t_cylinder *cylinder, t_ray ray);
double			intersection_plane(t_plane *plane, t_ray ray);
double			intersection_cone(t_cone *cone, t_ray ray);
void			draw(t_env *e);
void			apply_rotation(t_coord *rotation, t_coord *normal);
void			check_intersec_light(double *intersec,
				t_coord inter, t_ray spot);
void			adjust_color(t_color *new_color);
void			test_objects(t_list *objects, t_ray ray, double *t);
double			check_min(double delta, double a, double b, double c);
double			intersection_cone(t_cone *cone, t_ray ray);
double			intersection_plane(t_plane *plane, t_ray ray);
double			intersection_cylinder(t_cylinder *cylinder, t_ray ray);
double			intersection_sphere(t_sphere *sphere, t_ray ray);
void			debug(t_color *col, t_object *object);
t_ray			init_ray(t_env *e, t_coord pos);
void			init_view(t_env *e);
double			check_min(double delta, double a, double b, double c);
void			mlx_put_pixel_to_image(t_env *e, int x, int y, t_color c);
double			get_a(t_var v, t_ray ray);
double			get_b(t_var v, t_ray ray, t_coord *position);
double			get_c(t_var v, t_ray ray, t_coord *position);
t_coord			tmp2(t_coord delt_p, t_coord axe);
t_coord			tmp1(t_ray ray, t_coord axe);
int				parse_cone(t_env *e, char *line, int *i, int fd);
int				parse_cylinder(t_env *e, char *line, int *i, int fd);
int				parse_plane(t_env *e, char *line, int *i, int fd);
int				parse_sphere(t_env *e, char *line, int *i, int fd);
int				parse_cube(t_env *e, char *line, int *i, int fd);
t_cone			*new_cone();
t_cylinder		*new_cylinder();
t_plane			*new_plane();
t_cube			*new_cube();
t_sphere		*new_sphere();
t_light			*new_light();
void			trim_to_double_point(char **tmp);
int				parse_cam_line(t_env *e, char *line, int *i, int fd);
int				parse_rotation(char *str, t_coord *rot);
int				parse_position(char *str, t_coord *pos);
int				parse_size(char *str, double *size);
int				parse_color(char *str, t_color *c);
int				not_int(char *str);
int				not_double(char *str);
int				parse_light_line_item(t_env *e, char **tab, int fd);
double			getcolorvalue(int color);
int				parse_light(t_env *e, char *line, int *i, int fd);
t_color			addcolor(t_color c1, t_color c2);
t_color			calcolor(t_env *e, t_list *objects, t_ray ray, t_list *lights);
t_color			getreflexion(t_env *e,
				t_coord normal, t_ray ray, int i, t_coord inter);
t_object		*intersection(t_list *objects, t_ray ray, double *t);
void			ft_init_col(t_color *col);

#endif
