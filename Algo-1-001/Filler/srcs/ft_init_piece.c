
#include <stdlib.h>
#include "filler.h"

static int	ft_get_num(char c)
{
	if (c == '.')
		return (0);
	else
		return (3);
}

static void	ft_fill_token(t_piece *piece)
{
	int		y;
	int		x;
	char	*line;

	y = -1;
	while (++y < piece->y_max)
	{
		get_next_line(0, &line);
		x = -1;
		piece->tab[y] = (int *)malloc(sizeof(int) * (piece->x_max + 1));
		while (++x < piece->x_max)
			piece->tab[y][x] = ft_get_num(line[x]);
		free(line);
	}
}

void		ft_init_piece(char *line, t_piece *piece)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	piece->y_max = ft_atoi(tmp[1]);
	piece->x_max = ft_atoi(tmp[2]);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	piece->tab = (int **)malloc(sizeof(int *) * (piece->y_max + 1));
	free(line);
	ft_fill_token(piece);
}
