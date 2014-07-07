#ifndef __ft_PRINTF__
# define __ft_PRINTF__
# include	<stdarg.h>

typedef struct	s_flag
{
	int		data;
	struct	s_flag *next;
} t_flag;

typedef struct	s_arg
{
	t_flag	*flags;
	int		width;
	int		precision;
	int		length;
	int		specifier;
	char		fakespec;
	char		*text;
	struct	s_arg *next;
} t_arg;

char	*cpy_str(char *src, int s, int e);
int		ft_push_flag(t_flag **list, int value);
int		is_flags(int cnt, char *str, char *val);
int		put_flags(int cnt, char *str, t_arg *args);
int     ft_char_isnum(char c);
int		put_width(int cnt, char *str, t_arg *args);
int		put_precision(int cnt, char *str, t_arg *args);
int		put_length(int cnt, char *str, t_arg *args);
int		put_specifier(int cnt, char *str, t_arg *args);
int		nbr_tobase(int n, char *base, char *sup);
int		ft_putallstr(char *str);
int	ft_getnbr(char *str);
int		ft_strlen(char *str);
int		ft_push_args(t_arg **list, t_arg *element);
int		print_spaces(t_arg *args);
int		print_flags(t_arg *args, va_list ap);
int		print_spec(t_arg *args, va_list ap);
int		parser(char *str, va_list ap);
int		ft_printf(char *str, ...);
int		print_nbr_arg(int nbr, va_list ap);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		print_char_arg(int nbr, va_list ap);
#endif
