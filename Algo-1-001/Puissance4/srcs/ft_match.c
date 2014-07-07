
#include "ft_puissance4.h"

void			change_player(void)
{
	if (glob_obj(0)->player == 0)
		glob_obj(0)->player = 1;
	else
		glob_obj(0)->player = 0;
}

static int		ft_mult(t_tab *obj)
{
	return (obj->lines * obj->cols);
}

void	ft_match(t_tab *obj, int i)
{
	int			count;

	count = 0;
	while (aff_tab(glob_obj(0)->tab), !obj->end && count < ft_mult(obj))
	{
		if (!is_win(obj))
		{
			if (!obj->player)
			{
				ft_putendl("YOUR TURN");
				i = real_player(obj);
			}
			else
			{
				ft_putendl("COMPUTER TURN");
				i = ia_turn(glob_obj(0)->tab);
			}
			if (check_col(i) == 0)
			{
				ins_col(i);
				obj->count_max--;
			}
		}
		else
			break ;
	}
}
