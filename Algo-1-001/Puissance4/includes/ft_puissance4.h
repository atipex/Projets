
#ifndef FT_PUISSANCE_4
# define FT_PUISSANCE_4
# include "libft.h"
# define EMPTY		' '
# define IA			'O'
# define PLAYER		'X'

typedef struct		s_tab
{
	int			lines;
	int			cols;
	int			count_max;
	int			player;
	int			end;
	int			winner;
	char		**tab;
}					t_tab;

int		check_data(int ac, char **av);
int		ft_check_digit(char *str);
t_tab	*fill_obj(char *s1, char *s2, t_tab *obj);
char	**tab_create(int line, int cols);
char	*ft_strnew_tab(size_t size);
t_tab	*glob_obj(int i);
void	welcome(t_tab *obj);
void	aff_tab(char **tab);
void	free_tab(char **tab1);
void	ft_match(t_tab *obj, int i);
void	change_player(void);
int		check_col(int i);
void	ins_col(int i);
int		real_player(t_tab *obj);
int		ia_turn(char **tab);
int		vert_check(char **tab, int x, int y, int x_m);
int		hor_check(char **tab, int x, int y, int y_m);
int		diag_1_check(char **tab, int x, int y, int x_m);
char	**tab_cpy(char **tab);
int		is_win(t_tab *obj);
int		try_ww(int c, t_tab *obj, int i, int j);
#endif /* !FT_PUISSANCE_4 */
