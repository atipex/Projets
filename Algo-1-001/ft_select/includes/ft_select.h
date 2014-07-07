#ifndef FT_SELECT_H
# define FT_SELECT_H
typedef struct	s_env
{
	int			lines;
	int			colones;
	int			count_lines;
}				t_env;
int		tputs_putchar(int c);
int		ft_select(int argc, char **argv);
#endif /* !FT_SELECT_H */
