#ifndef CORE_WAR_H
# define CORE_WAR_H

# include "libft.h"
# include "op.h"

# define READ_SZ (4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
# define CURSOR_MAGIC (0)
# define CURSOR_NM (CURSOR_MAGIC + 4)
# define CURSOR_SZ (CURSOR_NM + PROG_NAME_LENGTH)
# define CURSOR_COM (CURSOR_SZ + 8)
# define ABS(x) (((x) < 0) ? -(x) : (x))

typedef unsigned char	t_charu;
typedef unsigned int	t_intu;

t_intu	g_winner_id;
char	*g_winner_name;
t_intu	g_pid;

typedef struct		s_cmd
{
	int		fct;
	int		type_args[3];
	t_charu	args[(IND_SIZE + REG_SIZE + DIR_SIZE) * 4];
}					t_cmd;

typedef struct	s_parse
{
	int		mag;
	int		size;
	char	*cont;
}				t_parse;

typedef struct		s_chp
{
	t_intu				f;
	t_intu				pid;
	int					carry;
	char				*name;
	char				*com;
	t_cmd				*cmd;
	t_intu				reg[REG_NUMBER];
	int					cycle;
	int					cycle_to_die;
	t_charu				*PC;
	t_parse				*parsing;
	struct s_chp		*nxt;
	struct s_chp		*prev;
}					t_chp;

typedef struct		s_cycle
{
	int		nbr_live;
	int		cycle_to_die;
	int		current_cycle;
}					t_cycle;


typedef struct		s_tab
{
	int		cycle;
	void	(*fct)(t_charu *, t_chp *);
}					t_tab;

t_cycle		*init_cycle(void);
void		giv_args_type(t_chp *chp, char *args_type);
void		giv_args(t_chp *chp, t_charu *a);
void		convert_dev(int nbr, char *args_type);
void		ft_er(char *str);
void		check_def(void);
t_charu		*init_arena(void);
int			check_cmd(int argc, char **argv);
int			check_c(char **argv, int i);
t_chp		*root(void);
void		add(t_chp *r);
void		del(t_chp *e);
char		*ft_ustrdnup(unsigned char *str, int n);
t_chp		*mchp(int argc, char **argv, t_charu *a);
void		init_chp(t_chp *chp, int id);
void		data_chp_d(int argc, char **argv, t_chp *r);
int			ft_pow(int n, int c);
int			convert_int(t_charu *a, int size);
void		ins_chp(t_chp *c, t_charu *a);
void		battle_start(int d, t_charu *a, t_chp *chp, t_cycle *c);
void		del_m_f(t_chp *r, t_chp *tmp);
void		clean(t_chp *chp, t_cycle *c, t_charu *a);
void		is_win(t_charu *a, t_chp *chp, t_cycle *c);
void		new_l(int i, int *line);
void		d_mem(t_chp *chp, t_cycle *c, t_charu *a);
void		conv_b(int nbr, int base);
int			spec_func(t_chp *chp, t_charu *a);
char		*ft_ustrndup(unsigned char *str, int n);
void		give_i(t_chp *chp, t_charu *a);
int			check_r(t_chp *chp, t_cycle *c);
void		check_i(t_chp *chp, t_charu *a);
void		check_cy(t_chp *chp, t_charu *a, t_cycle *c);
void		exec_i(t_chp *chp, t_charu *a, t_cycle *c);
t_charu		*new_add(t_charu *w, t_charu *a);
int			giv_reg_nbr(int reg);
int			giv_para_val(t_chp *chp, t_cmd *cmd, int ars, t_charu *a);
int			convert_int_instr(t_charu *args, int size, t_charu *a);
int			convert_int_init(t_charu *args, int size);
int			neg_conve_int(t_charu *args, int size);
int			neg_conve_int_instr(t_charu *args, int size, t_charu *a);
void		stock_conv_nbr(t_charu *tmp, t_charu *a, int value);
void		live(t_charu *a, t_chp *chp);
void		ld(t_charu *a, t_chp *chp);
void		st(t_charu *a, t_chp *chp);
void		add_(t_charu *a, t_chp *chp);
void		sub(t_charu *a, t_chp *chp);
void		and(t_charu *a, t_chp *chp);
void		or(t_charu *a, t_chp *chp);
void		xor(t_charu *a, t_chp *chp);
void		zjmp(t_charu *a, t_chp *chp);
void		ldi(t_charu *a, t_chp *chp);
void		sti(t_charu *a, t_chp *chp);
void		fork_(t_charu *a, t_chp *chp);
void		lld(t_charu *a, t_chp *chp);
void		lldi(t_charu *a, t_chp *chp);
void		lfork(t_charu *a, t_chp *chp);
void		aff(t_charu *a, t_chp *chp);
int			exec_live(t_chp *tmp, t_chp *chp);
int			ret_tab_i(int val, int value);
#endif /* !CORE_WAR_H */
