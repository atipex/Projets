#include <stdlib.h>
#include "corewar.h"

void	convert_dev(int nbr, char *args_type)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		args_type[i--] = nbr % 2;
		nbr /= 2;
	}
}

void	giv_args_type(t_chp *chp, char *args_type)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (args_type[i] || args_type[i + 1])
		{
			if (args_type[i] && args_type[i + 1])
				chp->cmd->type_args[i / 2] = IND_SIZE;
			else if (args_type[i])
				chp->cmd->type_args[i / 2] = DIR_SIZE;
			else if (args_type[i + 1])
				chp->cmd->type_args[i / 2] = T_REG;
			else
				chp->cmd->type_args[i / 2] = 0;
		}
		i += 2;
	}
}

void	giv_args(t_chp *chp, t_charu *a)
{
	int			i;
	int			size;
	t_charu		*tmp;

	size = chp->cmd->type_args[0] + chp->cmd->type_args[1];
	size += chp->cmd->type_args[2];
	i = -1;
	while (++i < size)
	{
		tmp = new_add(chp->PC + 2 + i, a);
		chp->cmd->args[i] = tmp[0];
	}
}

#include "corewar.h"
#include <stdlib.h>

void		del_m_f(t_chp *r, t_chp *tmp)
{
	t_chp	*t;

	t = r->nxt;
	while (t != r)
	{
		t = t->nxt;
		if (t->prev != tmp && t->prev->f == t->pid)
			del_m_f(r, t->prev);
	}
	del(tmp);
}

void		clean(t_chp *chp, t_cycle *c, t_charu *a)
{
	t_chp	*tmp;

	free(a);
	free(c);
	tmp = chp->nxt;
	while (tmp != chp)
	{
		tmp = tmp->nxt;
		del(tmp->prev);
	}
	free(chp);
	exit(0);
}

void		is_win(t_charu *a, t_chp *chp, t_cycle *c)
{
	if (g_winner_name)
	{
		ft_putstr("Le joueur ");
		ft_putstr(g_winner_name);
		ft_putstr(" (");
		ft_putnbr(g_winner_id);
		ft_putendl(") a gagne");
	}
	else
		ft_putendl("Egalitee");
	clean(chp, c, a);
}

void			battle_start(int d, t_charu *a, t_chp *chp, t_cycle *c)
{
	t_chp	*tmp;

	while (c->cycle_to_die > 0 && check_r(chp, c))
	{
		tmp = chp->nxt;
		while (tmp != chp)
		{
			check_cy(tmp, a, c);
			tmp->cycle_to_die++;
			tmp = tmp->nxt;
			if (c->nbr_live >= NBR_LIVE)
			{
				c->cycle_to_die -= CYCLE_DELTA;
				c->nbr_live = 0;
			}
		}
		if (c->current_cycle == d)
			d_mem(chp, c, a);
		c->current_cycle++;
	}
	is_win(a, chp, c);
}

#include "corewar.h"

t_tab		funct_tab[] =
{
	{10, live},
	{5, ld},
	{5, st},
	{10, add_},
	{10, sub},
	{6, and},
	{6, or},
	{6, xor},
	{20, zjmp},
	{25, ldi},
	{25, sti},
	{800, fork_},
	{10, lld},
	{50, lldi},
	{1000, lfork},
	{2, aff},
};

int		check_r(t_chp *chp, t_cycle *c)
{
	int		i;
	t_chp	*tmp;

	i = 0;
	tmp = chp->nxt;
	if (c->cycle_to_die <= 0)
		return (0);
	while (tmp != chp)
	{
		if (tmp->cycle_to_die < c->cycle_to_die)
		{
			if (!tmp->f)
				i++;
			tmp = tmp->nxt;
		}
		else
		{
			del_m_f(chp, tmp);
			tmp = chp->nxt;
			i = 0;
		}
	}
	return (i);
}

void		check_cy(t_chp *chp, t_charu *a, t_cycle *c)
{
	if (chp->cycle == 0)
		check_i(chp, a);
	else if (--chp->cycle == 1)
	{
		exec_i(chp, a, c);
		chp->cycle = 0;
	}
}

void		check_i(t_chp *chp, t_charu *a)
{
	if (*chp->PC > 0 && *chp->PC < 17)
	{
		chp->cycle = funct_tab[*chp->PC - 1].cycle;
		give_i(chp, a);
	}
	else
		chp->PC = new_add(chp->PC + 1, a);
}

void		exec_i(t_chp *chp, t_charu *a, t_cycle *c)
{
	int		args;

	if (spec_func(chp, a))
		args = 1;
	else
		args = 2;
	args += chp->cmd->type_args[0];
	args += chp->cmd->type_args[1];
	args += chp->cmd->type_args[2];
	funct_tab[chp->cmd->fct - 1].fct(a, chp);
	chp->cmd->type_args[0] = 0;
	chp->cmd->type_args[1] = 0;
	chp->cmd->type_args[2] = 0;
	if (chp->cmd->fct == 9 && chp->carry)
		return ;
	else if (chp->cmd->fct == 1)
		c->nbr_live++;
	chp->PC = new_add(chp->PC + args, a);
}

#include "corewar.h"
#include <stdlib.h>

static void	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(-1);
}

static int	check_n(int argc, char **argv, int i)
{
	int				num_champ;
	static char		champion_state[] = "0000";

	if (ft_strcmp(argv[i], "-n"))
		return (i);
	if (i + 2 < argc)
	{
		num_champ = ft_atoi(argv[i + 1]);
		if (num_champ <= 0 || num_champ > 4)
			print_error("Numero of champ must be between 1 and 4");
		if (champion_state[num_champ - 1] == '1')
			print_error("Can't use twice number of champions");
		champion_state[num_champ - 1] = 1;
		i += 2;
	}
	else
		print_error("Wrong number of arguments");
	return (i);
}

static int		check_a(int argc, char **argv, int i)
{
	int		adress;

	if (ft_strcmp(argv[i], "-a"))
		return (i);
	if (i + 2 < argc)
	{
		adress = ft_atoi(argv[i + 1]);
		if (adress < 0 || adress > MEM_SIZE - 1)
			print_error("Invalide adress position in memory");
		i += 2;
	}
	else
		print_error("Wrong number of arguments");
	return (i);
}

int		check_c(char **argv, int i)
{
	static int		nb_champ;
	int				size;

	size = ft_strlen(argv[i]);
	if (size < 4)
		print_error("Invalid file format");
	else if (ft_strcmp(&(argv[i][size - 4]), ".cor"))
		print_error("Invalid file format");
	nb_champ++;
	if (nb_champ > 4)
		print_error("Can't play with more than 4 players");
	return (++i);
}

int		check_cmd(int argc, char **argv)
{
	int		i;
	int		cycles;

	i = 1;
	cycles = -1;
	if (!ft_strcmp(argv[i], "-dump"))
	{
		if (i + 2 < argc)
		{
			if ((cycles = ft_atoi(argv[i + 1])) <= 0)
				print_error("Cycle must be positiv");
			i += 2;
		}
		else
			print_error("Wrong number of arguments");
	}
		while (i < argc)
		{
			i = check_n(argc, argv, i);
			i = check_a(argc, argv, i);
			i = check_c(argv, i);
		}
	return (cycles);
}

#include "corewar.h"

int		ft_pow(int n, int c)
{
	int		i;
	int		sum;

	i = 0;
	sum = 1;

	while (i++ < c)
		sum *= n;
	return (n);
}

int		convert_int(t_charu *a, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += a[i++] * ft_pow(256, exp--);
	return (sum);
}

int		convert_int_instr(t_charu *args, int size, t_charu *a)
{
	int			i;
	int			exp;
	int			sum;
	t_charu		*tmp;

	if (args[0] >= 128)
		return (neg_conve_int_instr(args, size, a));
	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
	{
		tmp = new_add(args + i++, a);
		sum += tmp[0] * ft_pow(256, exp--);
	}
	return (sum);
}

void		stock_conv_nbr(t_charu *tmp, t_charu *a, int value)
{
	int			i;
	int			val;
	t_charu		tab[4];

	i = 3;
	val = value;
	while (i >= 0)
	{
		tab[i--] = (val >= 0 ? value % 256 : value ? 255 + value % 256 + 1 :
				255 +  value % 256);
		value /= 256;
	}
	i = 0;
	while (i < 4)
	{
		tmp[0] = tab[i++];
		tmp = new_add(tmp + 1, a);
	}
}

int		convert_int_init(t_charu *args, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += args[i++] * ft_pow(256, exp--);
	return (sum);
}


#include "corewar.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	g_c_c(int fd, t_chp *c)
{
	int		i;
	int		j;
	int		sum;
	int		ret;
	t_charu	buffer[READ_SZ];

	sum = 0;
	i = 0;
	while ((ret = read(fd, buffer, READ_SZ)) > 0)
	{
		if ((sum += ret) > MEM_SIZE)
			ft_er("Champ too heavy");
		j = -1;
		while (++j < sum)
			c->parsing->cont[i + j] = buffer[j];
		i += (j + 1);
		if (sum != c->parsing->size)
			ft_er("Champ->size is bad");
	}
}

static void		g_d(char *file, t_chp *c)
{
	int		fd;
	t_charu	buffer[READ_SZ];

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_er("Can't open file");
	if (read(fd, buffer, READ_SZ) < READ_SZ)
		ft_er("Can't read file");
	c->parsing->mag = convert_int_init(buffer, 4);
	if (c->parsing->mag != COREWAR_EXEC_MAGIC)
		ft_er("Magic_code is wrong");
	if (!(c->name = ft_ustrndup(buffer + CURSOR_NM, PROG_NAME_LENGTH)))
		ft_er("Malloc() error");
	c->parsing->size = convert_int_init(buffer + CURSOR_SZ, 8);
	if (c->parsing->size <= 0 || c->parsing->size > MEM_SIZE - 1)
		ft_er("Size file invalide");
	if (!(c->com = ft_ustrndup(buffer + CURSOR_COM, COMMENT_LENGTH)))
		ft_er("Error malloc()");
	g_c_c(fd, c);
	if (close(fd) == -1)
		ft_er("Error close()");
}

static int		good_id(int *start, char stat[4])
{
	while (*start < 4)
	{
		if (stat[*start] == '0')
		{
			*start += 1;
			return (*start);
		}
		*start += 1;
	}
	return (0);
}

static void		g_n_t(int argc, char **argv, char stat[4])
{
	int		i;
	int		i_n;

	i = -1;
	while (++i < argc)
	{
		if (i >= 3)
		{
			if (!ft_strcmp(argv[i - 2], "-n"))
			{
				if ((i_n = ft_atoi(argv[i - 1])) > 0)
				{
					stat[i_n - 1] = '1';
				}
			}
		}
	}
}

void	data_chp_d(int argc, char **argv, t_chp *r)
{
	static char		chp[] = "0000";
	int				start;
	int				id;
	int				i;
	int				size;

	g_n_t(argc, argv, chp);
	start = 0;
	i = 0;
	while (++i < argc)
	{
		size = ft_strlen(argv[i]);
		if (size >= 4 && !ft_strcmp(&(argv[i][size - 4]), ".cor"))
		{
			add(r);
			if ((r->prev->parsing = malloc(sizeof(t_parse))) == NULL)
				ft_er("Error malloc()");
			if (i >= 3 && !ft_strcmp(argv[i - 2], "-n") &&
				((id = ft_atoi(argv[i - 1])) > 0))
					init_chp(r->prev, id);
			else
				init_chp(r->prev, good_id(&start, chp));
			g_d(argv[i], r->prev);
		}
	}
}


#include <stdlib.h>
#include "corewar.h"

void	conv_b(int nbr, int base)
{
	int		mod;

	mod = nbr % base;
	nbr /= base;
	if (nbr)
		conv_b(nbr, base);
	if (mod > 9)
		ft_putchar('A' + (mod % 10));
	else
		ft_putnbr(mod);
}

void	new_l(int i, int *line)
{
	ft_putchar('\n');
	if (i < MEM_SIZE)
	{
		conv_b(*line, 16);
		ft_putstr("\t: ");
		*(line) += 1;
	}
}

void		d_mem(t_chp *chp, t_cycle *c, t_charu *a)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	conv_b(line++, 16);
	ft_putstr("\t: ");
	while (i < MEM_SIZE)
	{
		if (a[i] < 17)
			ft_putchar('0');
		conv_b((int)a[i], 16);
		i++;
		if (i % 16 == 0)
			new_l(i, &line);
		else if (i < MEM_SIZE)
			ft_putchar(' ');
	}
	clean(chp, c, a);
}

#include "corewar.h"
#include <stdlib.h>

t_cycle		*init_cycle(void)
{
	t_cycle		*s;

	if ((s = malloc(sizeof(*s))) == NULL)
	{
		ft_putendl_fd("Can't malloc.", 2);
		exit(-1);
	}
	s->nbr_live = 0;
	s->cycle_to_die = CYCLE_TO_DIE;
	s->current_cycle = 1;
	return (s);
}


#include "corewar.h"
#include <stdlib.h>

t_charu		*init_arena(void)
{
	int			i;
	t_charu		*arena;

	i = 0;
	if ((arena = malloc(sizeof(t_charu) * MEM_SIZE)) == NULL)
		ft_er("Can't malloc()");
	while (i < MEM_SIZE)
		arena[i++] = 0;
	return (arena);
}

t_cycle		*init_cycles(void)
{
	t_cycle		*c;

	if ((c = malloc(sizeof(*c))) == NULL)
		ft_er("Error malloc()");
	c->nbr_live = 0;
	c->cycle_to_die = CYCLE_TO_DIE;
	c->current_cycle = 1;
	return (c);
}

void		init_chp(t_chp *chp, int id)
{
	int		i;

	i = 1;
	chp->reg[0] = id;
	chp->pid = id;
	chp->f = 0;
	while (i < REG_NUMBER)
		chp->reg[i++] = 0;
	chp->cycle = 0;
	chp->cycle_to_die = 0;
	chp->carry = 0;
	chp->cmd = malloc(sizeof(*(chp->cmd)));
	chp->parsing->cont = malloc(MEM_SIZE);
	if (chp->cmd == NULL || chp->parsing->cont == NULL)
		ft_er("Error on malloc()");
	chp->cmd->type_args[0] = 0;
	chp->cmd->type_args[1] = 0;
	chp->cmd->type_args[2] = 0;
}

t_chp		*mchp(int argc, char **argv, t_charu *a)
{
	t_chp	*t;

	t = root();
	data_chp_d(argc, argv, t);
	ins_chp(t, a);
	return (t);
}

#include "corewar.h"

static int		sum_mem_c(t_chp *c)
{
	t_chp		*tmp;
	int			sum;

	tmp = c->nxt->nxt;
	sum = 0;
	while (tmp != c)
	{
		sum += tmp->parsing->size;
		tmp = tmp->nxt;
	}
	return (sum);
}

static int		count_c(t_chp *c)
{
	t_chp	*tmp;
	int		count;

	tmp = c->nxt;
	count = 0;
	while (tmp != c)
	{
		count++;
		tmp = tmp->nxt;
	}
	return (count);
}

static void		put_mem(t_chp *c)
{
	int		i;

	i = 0;
	while (i < c->parsing->size && i < MEM_SIZE)
	{
		c->PC[i] = c->parsing->cont[i];
		i++;
	}
}

static void		p_o(t_chp *c, t_charu *a)
{
	t_chp		*tmp;
	int			pos;
	int			m_l;
	int			marg;
	int			sum_mem;

	pos = 0;
	tmp = c->nxt;
	m_l = MEM_SIZE - tmp->parsing->size;
	if ((sum_mem = sum_mem_c(c)) > m_l)
		ft_er("No enought memory space");
	marg = ((m_l - sum_mem) / count_c(c));
	tmp = tmp->nxt;
	while (tmp != c)
	{
		pos += (marg + tmp->prev->parsing->size);
		tmp->PC = &(a[pos]);
		put_mem(tmp);
		tmp = tmp->nxt;
	}
}

void		ins_chp(t_chp *c, t_charu *a)
{
	t_chp	*tmp;

	tmp = c->nxt;
	tmp->PC = &(a[0]);
	put_mem(tmp);
	if (tmp->nxt != c)
		p_o(c, a);
}

#include <stdlib.h>
#include "corewar.h"

int		spec_func(t_chp *chp, t_charu *a)
{
	t_charu		*tmp;

	if (chp->cmd->fct == 1)
		chp->cmd->type_args[0] = 4;
	else if (chp->cmd->fct == 9)
	{
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 1, a);
		chp->cmd->type_args[0] = tmp[0];
		tmp = new_add(chp->PC + 2, a);
		chp->cmd->type_args[1] = tmp[0];
	}
	else if (chp->cmd->fct == 12 || chp->cmd->fct == 15)
	{
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 1, a);
		chp->cmd->type_args[0] = 2;
		tmp = new_add(chp->PC + 2, a);
		chp->cmd->type_args[1] = 2;
	}
	else
		return (0);
	return (1);
}

void	give_i(t_chp *chp, t_charu *a)
{
	t_charu		*tmp;
	char		args_type[8];

	chp->cmd->fct = chp->PC[0];
	if (spec_func(chp, a))
		return ;
	tmp = new_add(chp->PC + 1, a);
	convert_dev(tmp[0], args_type);
	giv_args_type(chp, args_type);
	giv_args(chp, a);
}


#include <stdlib.h>
#include "corewar.h"

t_chp		*root(void)
{
	t_chp	*f;

	if ((f = malloc(sizeof(*f))) == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(-1);
	}
	f->nxt = f;
	f->prev = f;
	f->pid = -1;
	return (f);
}

void		add(t_chp *r)
{
	t_chp	*f;

	if ((f = malloc(sizeof(*f))) == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(-1);
	}
	f->nxt = r;
	f->prev = r->prev;
	r->prev->nxt = f;
	r->prev = f;
}

void	del(t_chp *e)
{
	if (!e->f)
	{
		free(e->com);
		free(e->parsing->cont);
		free(e->parsing);
	}
	e->prev->nxt = e->nxt;
	e->nxt->prev = e->prev;
	free(e->cmd);
	free(e);
}

#include "corewar.h"
#include <stdlib.h>

void	check_def(void)
{
	if (T_REG != 1
		|| T_DIR != 2
		|| T_IND != 4
		|| IND_SIZE != 2
		|| DIR_SIZE != 4
		|| REG_SIZE != 4)
	{
		ft_putendl_fd("Error wrong define", 2);
		exit(-1);
	}
}

#include "corewar.h"

void	corewar(int argc, char **argv)
{
	int			d;
	t_charu		*arena;
	t_cycle		*cycles;
	t_chp		*chp;

	g_pid = 5;
	g_winner_id = 0;
	g_winner_name = NULL;
	arena = init_arena();
	cycles = init_cycle();
	d = check_cmd(argc, argv);
	chp = mchp(argc, argv, arena);
	battle_start(d, arena, chp, cycles);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_def();
		corewar(argc, argv);
	}
	else
	{
		ft_putstr_fd("./corewar [-dumb nbr-cycle] ", 2);
		ft_putendl_fd("[[-n prog_number] [-a lad address] [prog_name]]", 2);
	}
	return (0);
}


#include "corewar.h"

int		neg_conve_int(t_charu *args, int size)
{
	int		i;
	int		exp;
	int		sum;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
		sum += (255 - args[i++]) * ft_pow(256, exp--);
	return ((sum + 1) * -1);
}

int		neg_conve_int_instr(t_charu *args, int size, t_charu *a)
{
	int			i;
	int			exp;
	int			sum;
	t_charu		*tmp;

	i = 0;
	exp = size - 1;
	sum = 0;
	while (exp >= 0)
	{
		tmp = new_add(args + i++, a);
		sum += (255 - tmp[0]) * ft_pow(256, exp--);
	}
	return ((sum + 1) * -1);
}
#include "corewar.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive"},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index"},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index"},
	{"fork", 1, {T_DIR}, 12, 800, "fork"},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index"},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
	{"aff", 1, {T_REG}, 16, 2, "aff"},
	{0, 0, {0}, 0, 0, 0}
};

#include "corewar.h"
#include <stdlib.h>

void	ft_er(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}

char	*ft_ustrndup(unsigned char *str, int n)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen((char*)str) + 1);
	if (s == NULL)
		exit(-1);
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}


#include "corewar.h"
#include <stdio.h>

void		live(t_charu *a, t_chp *chp)
{
	t_chp	*tmp;

	tmp = chp;
	(void) a;
	if (exec_live(tmp, chp))
		return ;
	tmp = tmp->nxt;
	while (tmp != chp)
	{
		if (exec_live(tmp, chp))
			return ;
		tmp = tmp->nxt;
	}
}

void	ld(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	j = giv_reg_nbr(j);
	chp->carry = i ? 0 : 1;
	chp->reg[j] = i;
}

void		st(t_charu *a,t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		chp->reg[giv_reg_nbr(j)] = i;
	else if (chp->cmd->type_args[1] == 2)
	{
		j = convert_int(chp->cmd->args + chp->cmd->type_args[0], 2);
		stock_conv_nbr(chp->PC+ j, a, i);
	}
}

void		add_(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i + j) ? 0 : 1;
	chp->reg[k] = i + j;
}

void		sub(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i - j) ? 0 : 1;
	chp->reg[k] = i - j;
}


#include <stdio.h>
#include "corewar.h"

void		and(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		i = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i & j) ? 0 : 1;
	chp->reg[k] = i & j;
}

void		or(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i | j) ? 0 : 1;
	chp->reg[k] = i | j;
}

void		xor(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;
	int		k;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	k = giv_reg_nbr(k);
	chp->carry = (i ^ j) ? 0 : 1;
	chp->reg[k] = i ^ j;
}

void		zjmp(t_charu *a, t_chp *chp)
{
	int		sum;

	if (chp->carry == 0)
		return ;
	sum = convert_int(chp->cmd->args, chp->cmd->type_args[0]);
	chp->PC = new_add(chp->PC + sum, a);
}

void		ldi(t_charu *a, t_chp *chp)
{
	int			i;
	int			j;
	int			k;
	int			val;
	t_charu		*tmp;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	tmp = chp->PC + i % IDX_MOD;
	tmp = new_add(tmp, a);
	val = convert_int_instr(tmp, IND_SIZE, a) + j;
	tmp = chp->PC + val % IDX_MOD;
	tmp = new_add(tmp, a);
	k = giv_reg_nbr(k);
	val = convert_int_instr(tmp, REG_SIZE, a);
	chp->carry = val ? 0 : 1;
	chp->reg[k] = val;
}


#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

void		sti(t_charu *a, t_chp *chp)
{
	int			i;
	int			j;
	int			k;
	t_charu		*tmp;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	if (chp->cmd->type_args[2] == 1)
		k = chp->reg[giv_reg_nbr(k)];
	tmp = chp->PC + (j + k) % IDX_MOD;
	tmp = new_add(tmp, a);
	stock_conv_nbr(tmp, a, i);
}

void		fork_(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = 0;
	if (chp->f > 0)
		return ;
	j = convert_int(chp->cmd->args, 2) % IDX_MOD;
	add(chp);
	chp->prev->PC = new_add(chp->PC + j, a);
	chp->prev->reg[0] = g_pid;
	chp->prev->pid = g_pid++;
	while (i < REG_NUMBER)
	{
		chp->prev->reg[i] = chp->reg[i];
		i++;
	}
	chp->prev->cycle = 0;
	chp->prev->carry = chp->carry;
	chp->prev->f = chp->pid;
	chp->prev->cycle_to_die = chp->cycle_to_die;
	chp->prev->cmd = malloc(sizeof(*(chp->prev->cmd)));
	if (chp->prev->cmd == NULL)
		ft_er("Malloc() Fail");
	chp->prev->cmd->type_args[0] = 0;
	chp->prev->cmd->type_args[1] = 0;
	chp->prev->cmd->type_args[2] = 0;
}

void		lld(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	j = giv_para_val(chp, chp->cmd, 2, a);
	chp->carry = i ? 0 : 1;
	chp->reg[j] = i;
}

void		lldi(t_charu *a, t_chp *chp)
{
	int			i;
	int			j;
	int			k;
	int			val;
	t_charu		*tmp;

	i = giv_para_val(chp, chp->cmd, 0, a);
	j = giv_para_val(chp, chp->cmd, 1, a);
	k = giv_para_val(chp, chp->cmd, 2, a);
	if (chp->cmd->type_args[0] == 1)
		i = chp->reg[giv_reg_nbr(i)];
	if (chp->cmd->type_args[1] == 1)
		j = chp->reg[giv_reg_nbr(j)];
	tmp = chp->PC + i;
	tmp = new_add(tmp, a);
	val = convert_int_instr(tmp, IND_SIZE, a) + j;
	tmp = chp->PC + val;
	tmp = new_add(tmp, a);
	k = giv_reg_nbr(k);
	val = convert_int_instr(tmp, REG_SIZE, a);
	chp->carry = val ? 0 : 1;
	chp->reg[k] = val;
}

void		lfork(t_charu *a, t_chp *chp)
{
	int		i;
	int		j;

	i = 1;
	j = convert_int(chp->cmd->args, 2);
	chp->carry = j ? 0 : 1;
	add(chp);
	chp->prev->PC = new_add(chp->PC + j, a);
	chp->prev->reg[0] = g_pid;
	chp->prev->pid = g_pid++;
	while (i < REG_NUMBER)
	{
		chp->prev->reg[i] = chp->reg[i];
		i++;
	}
	chp->prev->cycle = 0;
	chp->prev->carry = chp->carry;
	chp->prev->f = chp->pid;
	chp->prev->cycle_to_die = chp->cycle_to_die;
	chp->prev->cmd = malloc(sizeof(*(chp->prev->cmd)));
	if (chp->prev->cmd == NULL)
		ft_er("Malloc() fail");
	chp->prev->cmd->type_args[0] = 0;
	chp->prev->cmd->type_args[1] = 0;
	chp->prev->cmd->type_args[2] = 0;
}


#include <stdio.h>
#include "corewar.h"

void	aff(t_charu *a, t_chp *chp)
{
	int		i;

	i = giv_para_val(chp, chp->cmd, 0, a);
	if (chp->cmd->type_args[0] == 1)
	i = chp->reg[giv_reg_nbr(i)];
	i = i % 256;
	i = ABS(i);
	ft_putnbr(i);
}

int		exec_live(t_chp *tmp, t_chp *chp)
{
	if (tmp->pid == chp->reg[0])
	{
		if (!tmp->f)
		{
			ft_putstr("Le joueur ");
			ft_putnbr(tmp->pid);
			ft_putstr("(");
			ft_putstr(tmp->name);
			ft_putendl(") est en vie");
			g_winner_id = tmp->pid;
			g_winner_name = tmp->name;
		}
		tmp->cycle_to_die = 0;
		return (1);
	}
	return (0);
}


#include "corewar.h"

t_charu		*new_add(t_charu *w, t_charu *a)
{
	t_charu		*new;

	new = w;
	if ((long)new >= (long)a + MEM_SIZE)
	{
		new = (t_charu *)((long)new - (long)a);
		new = (t_charu *)((long)new % (long)MEM_SIZE);
		new = (t_charu *)((long)new + (long)a);
	}
	else if ((long)new < (long)a)
	{
		new = (t_charu *)((long)new % (long)MEM_SIZE);
		new = (t_charu *)((long)new + (long)a);
	}
	return (new);
}

int		giv_reg_nbr(int reg)
{
	reg -= 1;
	reg = ((reg >= 0) ? reg : -reg);
	reg = reg % REG_NUMBER;
	return (reg);
}

int		giv_para_val(t_chp *chp, t_cmd *cmd, int arg, t_charu *a)
{
	int			i;
	int			place;
	t_charu		*tmp;

	i = 0;
	place = 0;
	while (i < arg)
		place += cmd->type_args[i++];
	if (cmd->type_args[arg] == 1)
		return (cmd->args[place]);
	else if (cmd->type_args[arg] == 4)
		return (convert_int(cmd->args + place, cmd->type_args[arg]));
	else
	{
		i = convert_int(cmd->args + place, cmd->type_args[arg]);
		if (cmd->fct > 12)
			tmp = chp->PC + i;
		else
			tmp = chp->PC + (i % IDX_MOD);
		tmp = new_add(tmp, a);
		return (convert_int_instr(tmp, 4, a));
	}
}

