#include <stdlib.h>
#include "filler.h"

int		main(void)
{
	char	*line;
	int		num;
	t_board	board;
	t_piece	piece;

	num = 0;
	while (get_next_line(0, &line))
	{
		if (num == 0)
		{
			num = ft_init_player(line);
			free(line);
		}
		if (ft_strstr(line, "Plateau"))
			ft_init_board(line, &board);
		if (ft_strstr(line, "Piece"))
		{
			ft_init_piece(line, &piece);
			ft_play(num, board, piece);
			ft_destroy_board(&board);
			ft_destroy_piece(&piece);
		}
	}
	return (0);
}
