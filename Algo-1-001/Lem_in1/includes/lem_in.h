#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_path
{
	struct s_lab	*lab;
	struct s_path	*nxt;
}					t_path;

typedef struct		s_lab
{
	char			*name;
	int				x;
	int				y;
	char			start;
	char			used;
	t_path			*path;
	struct s_lab	*nxt;
}					t_lab;

typedef struct		s_f
{
	int			id;
	t_path		*path;
	struct s_f	*nxt;
}					t_f;

void	tabdel(char **tab);
int		tablen(char **tab);
void	add_f(t_f *f);
t_f		*create_f(void);
void	start_f(t_lab *lab, t_f *f);
t_f		*nb_f(void);
int		error_nb(char *line);
t_path	*path_made(void);
t_path	*path_add(t_path *path, t_lab *lab);
void	path_del(t_path *path);
void	del_f(t_f *f);
t_lab	*lab_error(t_lab*lab, int n);
int		error_start(t_lab *lab);
int		error_end(t_lab *lab);
t_lab	*lab_f(t_lab *lab, char **line, char start);
t_lab	*lab_made(char **line, char start);
void	lab_add(t_lab *lab, char **line, char start);
void	lab_del(t_lab *lab);
t_lab	*lab_find(t_lab *lab, char *name);
t_lab	*build_lab(t_lab *lab);
t_lab	*b_path(t_lab *lab, char *b, char **line);
int		solv_g(t_lab *lab);
int		move_a(t_f *f, t_path *l, char s);
int		already(t_f *t, t_lab *lab);
int		issok(t_f *f);
int		solv_lim(t_f *f, int l);
int		solv(t_f *f);
int		move_f(t_f *f, char s);
#endif /* !LEM_IN_H */
