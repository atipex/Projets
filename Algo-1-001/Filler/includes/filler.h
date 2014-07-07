#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_board
{
	int			x_max;
	int			y_max;
	int			**tab;
}				t_board;

typedef struct	s_piece
{
	int			x_max;
	int			y_max;
	int			**tab;
}				t_piece;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

int		ft_init_player(char *line);
void	ft_init_board(char *line, t_board *board);
void	ft_init_piece(char *line, t_piece *piece);
void	ft_play(int num, t_board board, t_piece piece);
void	ft_destroy_board(t_board *board);
void	ft_destroy_piece(t_piece *piece);

#endif
