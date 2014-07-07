#include <stdlib.h>
#include "filler.h"

void	ft_destroy_board(t_board *board)
{
	int		y;

	y = 0;
	while (y < board->y_max)
	{
		free(board->tab[y]);
		y++;
	}
	board->x_max = 0;
	board->y_max = 0;
	free(board->tab);
	board = NULL;
}

void	ft_destroy_piece(t_piece *piece)
{
	int		y;

	y = 0;
	while (y < piece->y_max)
	{
		free(piece->tab[y]);
		y++;
	}
	piece->x_max = 0;
	piece->y_max = 0;
	free(piece->tab);
	piece = NULL;
}
