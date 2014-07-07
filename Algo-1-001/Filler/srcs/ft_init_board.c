#include <stdlib.h>
#include "filler.h"

static int	ft_get_num(char c)
{
	if (c == '.')
		return (0);
	else if (c == 'x' || c == 'X')
		return (2);
	else
		return (1);
}

static void	ft_fill_map(t_board *board)
{
	int		y;
	int		x;
	char	*tmp;
	char	*line;

	y = -1;
	while (++y < board->y_max)
	{
		get_next_line(0, &line);
		x = -1;
		board->tab[y] = (int *)malloc(sizeof(int) * (board->x_max + 1));
		tmp = ft_strchr(line, ' ') + 1;
		while (++x < board->x_max)
		{
			board->tab[y][x] = ft_get_num(tmp[x]);
		}
		free(line);
	}
}

void		ft_init_board(char *line, t_board *board)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	board->y_max = ft_atoi(tmp[1]);
	board->x_max = ft_atoi(tmp[2]);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	board->tab = (int **)malloc(sizeof(int *) * (board->y_max + 1));
	free(line);
	get_next_line(0, &line);
	free(line);
	ft_fill_map(board);
}
