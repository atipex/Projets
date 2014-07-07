#include "corewar.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void		g_c_c(int fd, t_chp *c)
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

void			data_chp_d(int argc, char **argv, t_chp *r)
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

