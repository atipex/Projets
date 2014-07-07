#include <libft.h>
#include "filler.h"

static int	ft_play_test(t_board board, t_piece piece, t_pos pos, int num)
{
	t_pos	pos2;
	int		x2;
	int		y2;
	int		ok;

	ok = 0;
	y2 = -1;
	while (++y2 < piece.y_max)
	{
		x2 = -1;
		while (++x2 < piece.x_max)
		{
			pos2.y = pos.y + y2;
			pos2.x = pos.x + x2;
			if (board.tab[pos2.y][pos2.x] == num && piece.tab[y2][x2] == 3)
				ok++;
			else if (board.tab[pos2.y][pos2.x] != 0 && piece.tab[y2][x2] == 3)
				ok = 42;
		}
	}
	return (ok);
}

static void	ft_print(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		ft_play(int num, t_board b, t_piece p)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < b.y_max)
	{
		pos.x = -1;
		while (++pos.x < b.x_max)
		{
			if (pos.y + p.y_max < b.y_max && pos.x + p.x_max < b.x_max)
			{
				if (ft_play_test(b, p, pos, num) == 1)
				{
					ft_print(pos.y, pos.x);
					return ;
				}
			}
		}
	}
	ft_print(0, 0);
}
